#ifndef VISITOR_H__
#define VISITOR_H__

template<typename T, bool IsConst = true>
class Visitor;

template<typename T>
class Visitor<T, false>
{
public:
    virtual void visit(T& object) {};
    virtual ~Visitor() = delete;
};

template<typename T>
class Visitor<T, true>
{
public:
    virtual void visit(const T& object) {};
    virtual ~Visitor() = delete;
};

template<typename T>
class Visitable
{
public:
    virtual void accept(T& visitor) = 0;
    virtual ~Visitable() = default;
};

template<typename Self, typename T>
class VisitableImpl
{
public:
    virtual void accept(T& visitor)
    {
        visitor.visit(static_cast<Self&>(*this));
    }
    virtual ~VisitableImpl() = default;
};

#endif
    
