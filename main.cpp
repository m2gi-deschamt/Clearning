#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int main()
{
    // -----------------------------
    // Initialisation GLFW
    // -----------------------------
    if (!glfwInit())
        return -1;

    const char* glsl_version = "#version 330";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Puissance4 UI Responsive", NULL, NULL);
    if (!window) return -1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // -----------------------------
    // Initialisation ImGui
    // -----------------------------
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // -----------------------------
    // Variables UI
    // -----------------------------
    bool show_text = true;
    int counter = 0;

    // 0 = Menu, 1 = Jeu
    int current_window = 0;

    // -----------------------------
    // Boucle principale
    // -----------------------------
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // -----------------------------
        // Fenêtre responsive plein écran
        // -----------------------------
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);

        ImGui::Begin("Fenêtre Responsive", nullptr,
                     ImGuiWindowFlags_NoTitleBar |
                     ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoMove);

        ImVec2 avail = ImGui::GetContentRegionAvail();

        if (current_window == 0) {
            // Plein écran
            ImGui::SetNextWindowPos(ImVec2(0,0));
            ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);

            ImGui::Begin("Menu Accueil", nullptr,
                        ImGuiWindowFlags_NoTitleBar |
                        ImGuiWindowFlags_NoResize |
                        ImGuiWindowFlags_NoMove);

            float button_w = avail.x * 0.3f;
            float button_h = 50.0f;

            // Centré
            ImGui::SetCursorPosX((avail.x - button_w) * 0.5f);
            ImGui::SetCursorPosY((avail.y - button_h) * 0.5f);
            if (ImGui::Button("Jouer", ImVec2(button_w, button_h)))
                current_window = 1;

            ImGui::End();
        } else if (current_window == 1) {
            ImGui::SetNextWindowPos(ImVec2(0,0));
            ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);

            ImGui::Begin("Fenêtre Jeu", nullptr,
                        ImGuiWindowFlags_NoTitleBar |
                        ImGuiWindowFlags_NoResize |
                        ImGuiWindowFlags_NoMove);

            ImVec2 avail = ImGui::GetContentRegionAvail();

            // Découpage gauche / droite
            float left_width = avail.x * 0.3f;
            float right_width = avail.x - left_width;

            float button_width = left_width * 0.5f;

            // PANEL GAUCHE
            ImGui::BeginChild("LeftPanel", ImVec2(left_width, 0), true);

            // Top : 70% de la hauteur disponible
            float parent_height = ImGui::GetContentRegionAvail().y;
            ImGui::BeginChild("LeftPanelTop", ImVec2(0, parent_height * 0.7f), true);
            ImGui::Text("Options / Menu à gauche");
            ImGui::Checkbox("Afficher texte", &show_text);
            ImGui::EndChild();

            // Bottom : reste
            float bottom_height = ImGui::GetContentRegionAvail().y; // recalcul après top
            ImGui::BeginChild("LeftPanelBottom", ImVec2(0, bottom_height), true);
            if(ImGui::Button("Click me", ImVec2(button_width, 50))) {
                counter++;
            }
            ImGui::EndChild();

            ImGui::EndChild(); // LeftPanel


            ImGui::SameLine();

            // PANEL DROIT
            ImGui::BeginChild("RightPanel", ImVec2(right_width, 0), true);
            ImGui::Text("Zone du jeu à droite");
            float button_w = right_width * 0.4f;
            ImGui::SetCursorPosX((right_width - button_w) * 0.5f);
            if (ImGui::Button("Clique-moi", ImVec2(button_w, 40)))
                counter++;
            ImGui::SameLine();
            ImGui::Text("Compteur: %d", counter);

            ImGui::Spacing();
            ImGui::SetCursorPosX((right_width - button_w) * 0.5f);
            if (ImGui::Button("Retour au menu", ImVec2(button_w, 40)))
                current_window = 0;

            ImGui::EndChild();
            ImGui::End();
        }
        ImGui::End();
        // -----------------------------
        // Render
        // -----------------------------
        ImGui::Render();
        int w, h;
        glfwGetFramebufferSize(window, &w, &h);
        glViewport(0, 0, w, h);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // -----------------------------
    // Cleanup
    // -----------------------------
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}