#include "Engine.h"

Engine::Engine(int hp, const unsigned id, const char* manufacturer, const char* description)
    : CarPart(id, manufacturer, description)
{
    this->hp = hp;
}

const int Engine::GetHP() const
{
    return hp;
}

std::ostream& Engine::operator<<(std::ostream& os)
{
    os << this;
    os << " - " << hp << "hp" << '\n';
    return os;
}
