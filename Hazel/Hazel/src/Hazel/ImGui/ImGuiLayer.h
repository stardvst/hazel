#pragma once

#include "Hazel/Layer.h"

namespace Hazel
{

class MouseButtonPressedEvent;
class MouseButtonReleasedEvent;
class MouseScrolledEvent;
class MouseMovedEvent;
class KeyReleasedEvent;
class KeyPressedEvent;
class KeyTypedEvent;
class WindowCloseEvent;
class WindowResizeEvent;

// A debug layer
class HAZEL_API ImGuiLayer final : public Layer
{
public:
	ImGuiLayer();

	void onAttach() override;
	void onDetach() override;

	void onUpdate() override;
	void onEvent(Event &event) override;

private:
	bool onMouseButtonPressedEvent(MouseButtonPressedEvent &event);
	bool onMouseButtonReleasedEvent(MouseButtonReleasedEvent &event);
	bool onMouseScrolledEvent(MouseScrolledEvent &event);
	bool onMouseMovedEvent(MouseMovedEvent &event);
	bool onKeyReleasedEvent(KeyReleasedEvent &event);
	bool onKeyPressedEvent(KeyPressedEvent &event);
	bool onKeyTypedEvent(KeyTypedEvent &event);
	bool onWindowResizeEvent(WindowResizeEvent &event);

private:
	float m_fTime = 0.0f;

};

}
