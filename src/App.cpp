#define LD_ENTRYPOINT
#include "Luddite/Core/EntryPoint.hpp"
#include "pch.hpp"

class Project : public Luddite::Application
{
        public:
        Project()
        {
                CreateMainWindow("Luddite Project");
                LD_LOG_INFO("Main Window Created");
                ImGui::SetCurrentContext(m_pMainWindow->GetImGuiContext());
        }
        ~Project() {}

        void Initialize()
        {
                m_pMainWindow->GetLayerStack().PushLayer(std::make_shared<Luddite::EditorLayer>());
        }

        void OnUpdate(float delta_time)
        {
                m_pMainWindow->GetLayerStack().UpdateLayers(delta_time);
        }

        void OnFixedUpdate(float delta_time)
        {
                m_pMainWindow->GetLayerStack().UpdateLayersFixed(delta_time);
        }

        void OnRender(float lerp_alpha)
        {
                m_pMainWindow->GetLayerStack().RenderLayers(lerp_alpha, m_pMainWindow->GetRenderTarget());
        }

        void OnImGuiRender(float lerp_alpha)
        {
                m_pMainWindow->GetLayerStack().RenderLayersImGui(lerp_alpha, m_pMainWindow->GetRenderTarget());
        }
};

Luddite::Application* Luddite::CreateApplication()
{
        return new Project();
}
