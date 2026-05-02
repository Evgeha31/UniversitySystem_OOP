#pragma once

class AcademicSession; 

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update(AcademicSession* session) = 0; 
};