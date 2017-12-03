//
// sueda - geometry edits Z. Wood
// 3/16
//

#include <iostream>
#include "Particle.h"
#include "GLSL.h"
#include "MatrixStack.h"
#include "Program.h"
#include "Texture.h"


float randFloat(float l, float h)
{
	float r = rand() / (float) RAND_MAX;
	return (1.0f - r) * l + r * h;
}

void Particle::load()
{
	// Random initialization
	rebirth(0.0f);
}

// all particles born at the origin
void Particle::rebirth(float t)
{
	charge = randFloat(0.0f, 1.0f) < 0.5f ? -1.0f : 1.0f;
	m = 1.0f;
	d = randFloat(0.0f, 0.02f);
	x.x = randFloat(-20,20);
	x.y = randFloat(0.1f, 10.f);
   //z = randFloat(3.f, 12.f);
	x.z = randFloat(-20,20);
   gd.x = randFloat(-0.001, 0.001);
   gd.y = randFloat(-0.001, 0.001);
   gd.z = randFloat(-0.001, 0.001);
   x.z = randFloat(-20,20);//
	v.x = randFloat(-0.1f, 0.1f) * randFloat(-1.1f, 1.1f);
	v.y = 0.3 + randFloat(-0.1f, 0.1f);
	v.z = randFloat(-0.1f, 0.1f) * randFloat(-1.1f, 1.1f);
	lifespan = randFloat(10.f, 30.f);
	tEnd = t + lifespan;

	scale = randFloat(0.2f, 1.0f);
	color.r = randFloat(0.7f, 1.f);
	color.g = randFloat(0.7f, 1.f);
	color.b = randFloat(0.0f, 1.f);
	color.a = randFloat(0.5f, 1.f);
}

void Particle::update(float t, float h, const vec3 &g, const bool *keyToggles)
{
	if (t > tEnd)
	{
		rebirth(t);
	}

	// very simple update
	x += h * v;
   v += gd;
   v.x += sin(t/8) / 1000;
   v.y += cos(t/16) / 1000;
   v.z += (sin(t/8) * cos(t/16)) / 1000;
  
	color.a = (tEnd - t) / lifespan;
}
