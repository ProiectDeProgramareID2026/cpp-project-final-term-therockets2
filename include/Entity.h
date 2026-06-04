//
// Created by razva on 5/26/2026.
//

#ifndef CPP_PROJECT_PLANNING_THEROCKETS_ENTITY_H
#define CPP_PROJECT_PLANNING_THEROCKETS_ENTITY_H
#include <string>
using namespace std;

class Entity {
private:
    static int nextId;
    int id;
public:
    Entity();
    Entity(int id);
    virtual ~Entity() = default;
    int getId() const;

    [[nodiscard]] virtual string toString() const;
    [[nodiscard]] virtual string toFileEntry() const = 0;
};


#endif //CPP_PROJECT_PLANNING_THEROCKETS_ENTITY_H
