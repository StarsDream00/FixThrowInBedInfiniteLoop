/**
 * @file plugin.cpp
 * @brief The main file of the plugin
 */

/**
 * @brief The entrypoint of the plugin. DO NOT remove or rename this function.
 *
 */
#include <llapi/HookAPI.h>
#include <llapi/mc/Actor.hpp>
#include <llapi/mc/ItemActor.hpp>
#include <llapi/mc/ItemStack.hpp>
#include <llapi/mc/MovementInterpolatorComponent.hpp>

TInstanceHook(ItemActor const*, "?_drop@Actor@@IEAAPEBVItemActor@@AEBVItemStack@@_N@Z", Actor, ItemStack const& a2, bool a3) {
    MovementInterpolatorComponent* get = SymCall("??$tryGetComponent@UMovementInterpolatorComponent@@@EntityContextBase@@QEAAPEAUMovementInterpolatorComponent@@XZ", MovementInterpolatorComponent*, char*)((char*)this + 8);
    *(int*)(get + 28) = get->isActive();
    return original(this, a2, a3);
}
