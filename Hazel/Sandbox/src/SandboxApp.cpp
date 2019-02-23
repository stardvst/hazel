#include <Hazel.h>

class ExampleLayer final : public Hazel::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void onUpdate() override
	{
		HZ_INFO("ExampleLayer::update");
	}

	void onEvent(Hazel::Event &event) override
	{
		HZ_TRACE("{0}", event);
	}
};

class Sandbox final : public Hazel::Application
{
public:
	Sandbox()
	{
		pushLayer(new ExampleLayer);
	}
};

Hazel::Application *Hazel::createApplication()
{
	return new Sandbox;
}