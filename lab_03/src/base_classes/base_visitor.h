#ifndef LAB_03_BASE_VISITOR_H
#define LAB_03_BASE_VISITOR_H


class model;
class camera;
class composite;
class scene;

class base_visitor
{
public:
    virtual void visit(model & model) = 0;
    virtual void visit(camera & camera) = 0;
    virtual void visit(scene & scene) = 0;
    virtual void visit(composite & composite) = 0;
};

#endif //LAB_03_BASE_VISITOR_H
