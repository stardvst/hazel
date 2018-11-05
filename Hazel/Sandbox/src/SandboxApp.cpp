#include <Hazel.h>

class Sandbox : public Hazel::Application
{
public:

};

Hazel::Application *Hazel::CreateApplication()
{
	return new Sandbox;
}