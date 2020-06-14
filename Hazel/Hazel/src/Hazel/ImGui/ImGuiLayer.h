#pragma once

#include "Hazel/Layer.h"

namespace Hazel
{

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
	float m_fTime = 0.0f;

};

}
