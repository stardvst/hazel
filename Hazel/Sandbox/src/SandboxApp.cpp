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
		if (Hazel::Input::isKeyPressed(HZ_KEY_TAB))
			HZ_INFO("Tab key is pressed");
	}

	void onImGuiRender() override
	{
		//ImGui::Begin();
		//ImGui::Text("Hello World!");
		//ImGui::End();
	}

	void onEvent(Hazel::Event &event) override
	{
		if (event.getType() == Hazel::EEventType::KeyPressed)
		{
			const auto &e = static_cast<Hazel::KeyPressedEvent &>(event);
			HZ_TRACE("{0}", static_cast<char>(e.getCode()));
		}
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