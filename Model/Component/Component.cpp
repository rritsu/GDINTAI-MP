#include "Component.hpp"

using namespace components;

Component::Component(std::string strName, ComponentType EType) {
    /* [TODO] :
       Fill this constructor up accordingly. */
    this->pOwner = NULL;
    this->strName = strName;
    this->EType = EType;
}

Component::~Component() {
    /* [TODO] :
       Set the [pOwner] field to NULL.
       Set the [EType] field to [NONE]. */
    this->pOwner = NULL;
    this->EType = ComponentType::NONE;
}

void Component::attachOwner(GameObject* pOwner) {
    /* [TODO] :
       Set the [pOwner] field with the parameter. */
    this->pOwner = pOwner;
}

void Component::detachOwner() {
    /* [TODO] :
       Detach the component by deleting it. */
    delete this;
}

GameObject* Component::getOwner() {
    return this->pOwner;
}

ComponentType Component::getType() {
    return this->EType;
}

std::string Component::getName() {
    return this->strName;
}

void Component::setDeltaTime(sf::Time tDeltaTime) {
    this->tDeltaTime = tDeltaTime;
}

        