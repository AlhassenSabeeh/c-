#ifndef EXCEPTIONINTERFACE_H
#define EXCEPTIONINTERFACE_H

class Exeption{
public:
    Exeption();
    virtual ~Exeption();
    virtual const char* what();
    Exeption& Exeption(const Exeption &rhs);
    
}