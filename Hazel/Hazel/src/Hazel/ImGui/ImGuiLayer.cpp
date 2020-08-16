#include "hzpch.h"
#include "ImGuiLayer.h"
#include "Hazel/Application.h"
#include "Hazel/Events/MouseEvent.h"
#include "Hazel/Events/KeyEvent.h"

#include <GLFW/glfw3.h>

#include "imgui.h"
#include "examples/imgui_impl_opengl3.h"
#include "examples/imgui_impl_glfw.h"

namespace Hazel
{

ImGuiLayer::ImGuiLayer()
	: Layer("ImGuiLayer")
{
}

void ImGuiLayer::onAttach()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	ImGuiIO &io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
	io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

	ImGui::StyleColorsDark();

	ImGuiStyle &style = ImGui::GetStyle();
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		style.WindowRounding = 0.0f;
		style.Colors[ImGuiCol_WindowBg].w = 1.0f;
	}

	Application &app = Application::get();
	auto window = static_cast<GLFWwindow *>(app.getWindow().getNativeWindow());

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 410");
}

void ImGuiLayer::onDetach()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void ImGuiLayer::onImGuiRender()
{
}

void ImGuiLayer::begin()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void ImGuiLayer::end()
{
	ImGuiIO &io = ImGui::GetIO();
	Application &app = Application::get();
	io.DisplaySize = ImVec2(static_cast<float>(app.getWindow().getWidth()),
		static_cast<float>(app.getWindow().getHeight()));

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		GLFWwindow *context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(context);
	}
}

}
