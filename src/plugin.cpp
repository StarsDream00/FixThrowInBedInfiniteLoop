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

TInstanceHook(class ItemActor const*, "?_drop@Actor@@IEAAPEBVItemActor@@AEBVItemStack@@_N@Z", Actor, class ItemStack const& a2, bool a3) {
	auto get = SymCall("??$tryGetComponent@UMovementInterpolatorComponent@@@EntityContextBase@@QEAAPEAUMovementInterpolatorComponent@@XZ", struct MovementInterpolatorComponent*, char*)((char*)this + 8);
	*(int*)(get + 28) = 0;
	return original(this, a2, a3);
}
