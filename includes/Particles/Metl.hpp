#ifndef METL_H
#define METL_H
#include <Particles/Particle.hpp>

class Metl : public Particle
{
    public:
        Metl();
        virtual ~Metl();
        void Render(sf::Image&);
    private:
};

#endif // METL_H
