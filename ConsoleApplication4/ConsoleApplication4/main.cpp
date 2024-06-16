#include <GLFW/glfw3.h>
#include <iostream>
#include "Object.h"

const int WIDTH = 800;
const int HEIGHT = 600;

Player* player;
Ground* ground;
Obstacle* obstacle1;
Obstacle* obstacle2;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

static bool spacePressed = false; // 전역 변수로 설정하거나, 클래스 멤버 변수로 설정

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && !spacePressed) {
        player->jump();
        std::cerr << "점프" << std::endl;
        spacePressed = true;
    }

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE) {
        spacePressed = false;
    }

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


int main()
{
    // GLFW 초기화
    if (!glfwInit())
    {
        std::cerr << "GLFW 초기화 실패" << std::endl;
        return -1;
    }

    
        // GLFW 창 생성 및 설정
        GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Google Dino Run Copy Game", NULL, NULL);
    if (!window)
    {
        std::cerr << "GLFW 창 생성 실패" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // OpenGL 초기화
    glViewport(0, 0, WIDTH, HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, WIDTH, 0.0, HEIGHT, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    // 객체 생성
    player = new Player(100.0f, 100.0f, 50.0f); // 플레이어 생성
    ground = new Ground(0.0f, 100.0f, WIDTH, 10.0f); // 지면 생성
    obstacle1 = new Obstacle(WIDTH, 110.0f, 50.0f, 100.0f, 0.5f); // 낮은 장애물 생성
    obstacle2 = new Obstacle(WIDTH + 400.0f, 110.0f, 50.0f, 300.0f, 0.5f); // 높은 장애물 생성

    // 메인 렌더링 루프
    while (!glfwWindowShouldClose(window))
    {
        // 입력 처리
        processInput(window);

        // 입력 이벤트 처리 (키 입력 등)
        glfwPollEvents();

        // 배경색 설정 (하늘색)
        glClearColor(0.0f, 0.12f, 0.39f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 객체 그리기
        player->draw();
        ground->draw();

        player->updatePhysics(0.0001f); // 예시로 deltaTime을 0.1로 설정
        obstacle1->move(0.1f);  // 예시로 deltaTime을 0.1로 설정
        obstacle2->move(0.1f);

        // 장애물이 화면 왼쪽 끝을 넘어가면 다시 화면 오른쪽 끝에서 재사용
        if (obstacle1->getX() + obstacle1->getWidth() < 0) {
            obstacle1->setPosition(WIDTH, 110.0f);  // 다시 오른쪽 끝에서 시작
        }
        if (obstacle2->getX() + obstacle2->getWidth() < 0) {
            obstacle2->setPosition(WIDTH, 110.0f);  // 다시 오른쪽 끝에서 시작
        }

        obstacle1->draw();
        obstacle2->draw();

        // 충돌 검사
        if (player->checkCollisionWith(obstacle1) || player->checkCollisionWith(obstacle2))
        {
            std::cout << "게임 종료 - 충돌 발생!" << std::endl;
            // 게임 종료 로직 추가
            break;
        }

        // 화면에 그림 갱신
        glfwSwapBuffers(window);

        
    }

    // 객체 해제
    delete player;
    delete ground;
    delete obstacle1;
    delete obstacle2;

    // GLFW 종료
    glfwTerminate();
    return 0;
}