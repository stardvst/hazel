#include <Hazel.h>

class Sandbox : public Hazel::Application
{
public:

};

Hazel::Application *Hazel::createApplication()
{
	return new Sandbox;
}