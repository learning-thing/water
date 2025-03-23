#pragma once
#include <raylib.h>
#include "rlights.hpp"

class Water {
    private:
        Model waer = LoadModel("res/plane.glb");
        Shader shader = LoadShader("res/shader/water.vs", "res/shader/water.fs");
        int iTimeLoc;
        int viewposLoc;
        int lightPosLoc;
        float iTime;
        Vector3 LightPos = (Vector3){0, 5, 0};

    public:
        Water() {
            iTimeLoc = GetShaderLocation(shader, "iTime");
            viewposLoc = GetShaderLocation(shader, "mvp");
            lightPosLoc = GetShaderLocation(shader, "LightPos");
            SetShaderValue(shader, lightPosLoc, &LightPos, SHADER_UNIFORM_VEC3);
            waer.materials[0].shader = shader;

            
        }

        void update(float frametime) {
            iTime+=frametime;
            SetShaderValue(shader, iTimeLoc, &iTime, SHADER_UNIFORM_FLOAT);
            reload();
        }

        void Draw() {
            DrawModel(waer, (Vector3){0, 0, 0}, 1, WHITE);
        }

        void reload() {
            if (IsKeyPressed(KEY_R)) {
                UnloadShader(shader);
                shader = LoadShader("res/shader/water.vs", "res/shader/water.fs");
                iTimeLoc = GetShaderLocation(shader, "iTime");
                lightPosLoc = GetShaderLocation(shader, "LightPos");
                SetShaderValue(shader, lightPosLoc, &LightPos, SHADER_UNIFORM_VEC3);
                waer.materials[0].shader = shader;
            }
        }
};