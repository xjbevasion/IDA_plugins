#include <ida.hpp>
#include <idp.hpp>
#include <loader.hpp>
#include <kernwin.hpp>
#include "prac1.hpp"

extern plugin_t PLUGIN;

//--------------------------------------------------------------------------
//
//      Initialize.
//
//      IDA will call this function every time when the plugin gets
//      loaded in the memory.
//      If this function returns PLGUIN_SKIP when called the first time,
//      IDA will never load it again. If it returns PLUGIN_OK, IDA will
//      unload the plugin but remember that the plugin agreed to work with
//      the database. The plugin will be loaded again if the user invokes
//      it by pressing its hotkey or selecting it from the menu.
//      After the second load the plugin will stay on memory.
//      If this function returns PLUGIN_KEEP, IDA will keep the plugin
//      in the memory. In this case the initialization function can hook
//      into the processor module and user interface notification points.
//      See the hook_to_notification_point() function.
//
//      In this example we check the input file format and make the decision.
//      You may or may not check any other conditions to decide what you do:
//      whether you agree to work with the database or not.
//
int idaapi init(void)
{
	return PLUGIN_OK;
	// NB: if you register any hooks/callbacks in this function,
	// you MUST return PLUGIN_KEEP
}

//--------------------------------------------------------------------------
//      Terminate.
//      Usually this callback is empty.
//      The plugin should unhook from the notification lists if
//      hook_to_notification_point() was used.
//
//      IDA will call this function before unloading the plugin.

void idaapi term(void)
{
	// NB: if you registered any hooks/callbacks,
	// you MUST unregister them here or beforehand
}

//--------------------------------------------------------------------------
//
//      The plugin method
//
//      This is the main function of plugin.
//
//      It will be called when the user selects the plugin.
//
//              arg - the input argument, it can be specified in
//                    plugins.cfg file. The default is zero.
//
//

bool idaapi run(size_t size)
{
	//warning("plugin is called with arg %x\n", arg);
	msg("hello world!");
	Extrativefile();
	return true;


}

//--------------------------------------------------------------------------
char comment[] = "This is a sample plugin. It does nothing useful";

char help[] = "A sample skeleton plugin\n";

//--------------------------------------------------------------------------
// This is the preferred name of the plugin module in the menu system
// The preferred name may be overriden in plugins.cfg file

static char desired_name[] = "practice 1st demo plugin";

// This is the preferred hotkey for the plugin module
// The preferred hotkey may be overriden in plugins.cfg file
// Note: IDA won't tell you if the hotkey is not correct
//       It will just disable the hotkey.

static char desired_hotkey[] = "Alt-0";

//--------------------------------------------------------------------------
//
//      PLUGIN DESCRIPTION BLOCK
//
//--------------------------------------------------------------------------

plugin_t PLUGIN =
{
  IDP_INTERFACE_VERSION,
  PLUGIN_UNL,           // plugin flags
  init,                 // initialize
  term,                 // terminate. this pointer may be NULL.
  run,                  // invoke plugin
  comment,              // long comment about the plugin
						// it may appear in the status line
						// or as a hint

  help,                 // multiline help about the plugin

  desired_name,         // the preferred short name of the plugin
  desired_hotkey        // the preferred hotkey to run the plugin
};
