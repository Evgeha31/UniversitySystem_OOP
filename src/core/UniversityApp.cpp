#include "../../include/core/UniversityApp.hpp"
#include "../../include/core/Exceptions.hpp"
#include "../../include/database/FileDB.hpp"
#include <iostream>

using namespace std;

UniversityApp::UniversityApp() 
    : itFaculty("ФИВТ", nullptr), groupPRO("ПРО-329", 3, &itFaculty), 
      oop("ООП", 144, 4), math("Высшая математика", 120, 1), physics("Физика", 108, 2), db("Базы данных", 72, 3),
      
      s1(1, "Иван Иванов", "ivan", "123", "ZB-01", &groupPRO), 
      s2(2, "Мария Смирнова", "maria", "123", "ZB-02", &groupPRO),
      s3(3, "Петр Петров", "petr", "123", "ZB-03", &groupPRO),
      s4(4, "Алексей Сидоров", "alex", "123", "ZB-04", &groupPRO),
      s5(5, "Дарья Ковалева", "dasha", "123", "ZB-05", &groupPRO),
      
      profOOP(10, "Сергей Сергеевич", "serg", "admin", "Кафедра ИТ"),
      profMath(11, "Анна Николаевна", "anna", "admin", "Кафедра Математики"),
      profPhysics(12, "Игорь Валерьевич", "igor", "admin", "Кафедра Физики"),
      
      gbOOP(&oop, &groupPRO, "Лето 2024"), gbMath(&math, &groupPRO, "Лето 2024"),
      gbPhysics(&physics, &groupPRO, "Лето 2024"), gbDB(&db, &groupPRO, "Лето 2024"),
      
      summerSession("2023/2024", "Летняя"), order("104-СТ"), isRunning(true)
{
    profOOP.addDiscipline(&oop);
    profOOP.addDiscipline(&db);   
    profMath.addDiscipline(&math);
    profPhysics.addDiscipline(&physics);
    
    allUsers = {&s1, &s2, &s3, &s4, &s5, &profOOP, &profMath, &profPhysics};
    groupStudents = {&s1, &s2, &s3, &s4, &s5};

    summerSession.attachObserver(&order);
    summerSession.addGradebook(&gbOOP);
    summerSession.addGradebook(&gbMath);
    summerSession.addGradebook(&gbPhysics);
    summerSession.addGradebook(&gbDB);

    labCreator = make_unique<LabWorkCreator>();
    examCreator = make_unique<ExamCreator>();
}

void UniversityApp::run() {
    cout << "\n   СИСТЕМА ВУЗа \n\n";
    while (isRunning) handleLogin();
}

void UniversityApp::syncWithDatabase() {
    for (auto* gb : summerSession.getGradebooks()) gb->clearRecords();
    systemTasks.clear(); 
    
    FileDB::loadTasks(this);
    FileDB::loadGrades(this);
}

void UniversityApp::handleLogin() {
    syncWithDatabase();
    cout << "\nАВТОРИЗАЦИЯ (введите 'exit' в логин для выхода)\nЛогин: ";
    string login; cin >> login;
    if (login == "exit") {
        cout << "До свидания!\n"; isRunning = false;
    } else {
        cout << "Пароль: "; string pass; cin >> pass;
        User* currentUser = authenticateUser(login, pass);
        if (!currentUser) cout << "Неверный логин или пароль!\n";
        else {
            if (currentUser->isTeacher()) teacherMenu(dynamic_cast<Teacher*>(currentUser));
            else studentMenu(dynamic_cast<Student*>(currentUser));
        }
    }
}

User* UniversityApp::authenticateUser(const string& login, const string& pass) {
    User* foundUser = nullptr;
    for (auto* u : allUsers) {
        if (!foundUser && u->getLogin() == login && u->checkPassword(pass)) foundUser = u;
    }
    return foundUser;
}

void UniversityApp::studentMenu(Student* student) {
    bool loggedIn = true;
    while (loggedIn) {
        syncWithDatabase();
        cout << "\nКабинет: " << student->getName() << "\n1. Посмотреть оценки\n2. Мой профиль\n3. Выйти\nВыбор: ";
        string choice; cin >> choice;
        if (choice == "1") showStudentGrades(student);
        else if (choice == "2") { cout << "\nИНФОРМАЦИЯ О СТУДЕНТЕ\n"; student->printRole(); }
        else if (choice == "3") loggedIn = false;
    }
}

void UniversityApp::showStudentGrades(Student* student) {
    cout << "\nВаши оценки\n";
    bool hasAnyGrades = false;

    for (const auto* gb : summerSession.getGradebooks()) {
        bool hasGradesInThisDiscipline = false;
        for (const auto* rec : gb->getRecords()) {
            if (rec->getStudent() == student) {
                if (!hasGradesInThisDiscipline) {
                    cout << "\nДисциплина: " << gb->getDiscipline()->getName() << "\n";
                    hasGradesInThisDiscipline = true;
                }
                cout << " - " << rec->getTask()->getTitle() << " | Балл: " << rec->getScore() 
                     << " из " << rec->getTask()->getMaxScore();
                if (rec->getTask()->isFinal()) cout << " [ИТОГОВОЕ]";
                cout << "\n";
                hasAnyGrades = true;
            }
        }
    }
    if (!hasAnyGrades) cout << "Оценок пока нет.\n";
}

void UniversityApp::teacherMenu(Teacher* teacher) {
    bool loggedIn = true;
    while (loggedIn) {
        syncWithDatabase();
        cout << "\nПреподаватель: " << teacher->getName() << "\n1. Создать задание\n2. Оценить студента\n3. Закрыть сессию\n4. Мой профиль\n5. Выйти\nВыбор: ";
        string choice; cin >> choice;
        try {
            if (choice == "1") handleTaskCreation();
            else if (choice == "2") handleGrading(teacher);
            else if (choice == "3") handleSessionClose(teacher); 
            else if (choice == "4") { cout << "\nИНФОРМАЦИЯ О ПРЕПОДАВАТЕЛЕ \n"; teacher->printRole(); }
            else if (choice == "5") loggedIn = false;
        } catch (const UniversityException& ex) { cout << "\nОШИБКА: " << ex.what() << "\n"; }
    }
}

void UniversityApp::handleTaskCreation() {
    cout << "Тип (1 - Лаба, 2 - Экзамен): "; string type; cin >> type;
    cout << "Название: "; string title; cin >> title;
    if (type == "1") {
        auto t = labCreator->create(title, 5, "1");
        FileDB::saveTask("1", t.get(), "1");
        systemTasks.push_back(std::move(t)); cout << "Задание создано!\n";
    } else if (type == "2") {
        auto t = examCreator->create(title, 5, "20.06");
        FileDB::saveTask("2", t.get(), "20.06");
        systemTasks.push_back(std::move(t)); cout << "Задание создано!\n";
    }
}

void UniversityApp::handleGrading(Teacher* teacher) {
    if (systemTasks.empty()) { cout << "Нет заданий!\n"; return; }
    cout << "\nВыберите вашу дисциплину\n";
    auto discs = teacher->getDisciplines();
    for(size_t i=0; i<discs.size(); ++i) cout << i+1 << ". " << discs[i]->getName() << "\n";
    int dIdx; cin >> dIdx; Discipline* selectedDisc = discs[dIdx-1];

    Gradebook* targetGb = nullptr;
    for(auto* gb : summerSession.getGradebooks()) {
        if(gb->getDiscipline() == selectedDisc) targetGb = gb;
    }

    cout << "\n Выберите задание\n";
    for (size_t i = 0; i < systemTasks.size(); ++i) cout << i + 1 << ". " << systemTasks[i]->getTitle() << "\n";
    int taskIdx; cin >> taskIdx; Task* selectedTask = systemTasks[taskIdx - 1].get();

    cout << "\nВыберите студента\n";
    for (size_t i = 0; i < groupStudents.size(); ++i) cout << i + 1 << ". " << groupStudents[i]->getName() << "\n";
    int studIdx; cin >> studIdx; Student* selectedStudent = groupStudents[studIdx - 1];

    cout << "Балл: "; int score; cin >> score;
    
    GradeRecord newRec = teacher->gradeStudent(selectedStudent, selectedTask, score, "Сегодня");
    GradeRecord* pRec = new GradeRecord(newRec);
    
    targetGb->addGrade(pRec); 
    FileDB::saveGrade(pRec, selectedDisc->getName());
    
    cout << "Сохранено!\n";
}

void UniversityApp::handleSessionClose(Teacher* teacher) {
    FileDB::saveSignature(teacher->getId());
    std::set<int> sigs = FileDB::loadSignatures();
    
    cout << "\nВы успешно сдали ведомости по своим предметам.\n";
    if (sigs.size() >= 3) {
        cout << "Все 3 преподавателя сдали ведомости!\n";
        cout << " Сессия закрывается автоматически...\n";
        summerSession.closeSession();
        order.printOrder();
    } else {
        cout << "Ожидаем остальных преподавателей. Подписало: " 
             << sigs.size() << " из 3.\n";
    }
}

Student* UniversityApp::findStudentByLogin(const string& login) {
    for (auto* s : groupStudents) if (s->getLogin() == login) return s;
    return nullptr;
}
Task* UniversityApp::findTaskByTitle(const string& title) {
    for (auto& t : systemTasks) if (t->getTitle() == title) return t.get();
    return nullptr;
}

void UniversityApp::addLoadedGrade(GradeRecord* rec, const string& discName) {
    for (auto* gb : summerSession.getGradebooks()) {
        if (gb->getDiscipline()->getName() == discName) {
            gb->addGrade(rec);
            return;
        }
    }
} 