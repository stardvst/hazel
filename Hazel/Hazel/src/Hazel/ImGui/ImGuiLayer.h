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

	void onImGuiRender() override;

	void begin();
	void end();

private:
	float m_fTime = 0.0f;

};

}
