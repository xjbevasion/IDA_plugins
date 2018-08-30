#pragma once

#include <ida.hpp>
#include <idp.hpp>
#include <expr.hpp>
#include <bytes.hpp>
#include <loader.hpp>
#include <kernwin.hpp>

//extractive 

#define exmsg(...) msg("[Extrativefile]");\
						msg(__VA_ARGS__);\
						msg("\n");



inline void Extrativefile()
{
	TWidget *v = get_current_viewer();
	twinpos_t pos_start, pos_end;
	ea_t ea_start,ea_end;
	sval_t extrativesize = 0;
	if (read_selection(v, &pos_start, &pos_end))
	{
		ea_start = (pos_start.at)->toea();
		ea_end = (pos_end.at)->toea();
		extrativesize = ea_end - ea_start;
	}
	else
	{
		ea_start = get_screen_ea();
		extrativesize = 0x200;
	}
	bool ret = false;
	ret = ask_addr(&ea_start, "Input start addr");
	if (!ret)
	{
		exmsg("Get start addr failed!");
		return;
	}
	ret = ask_long(&extrativesize, "Input size");
	if (!ret)
	{
		exmsg("Get extrative size failed!");
		return;

	}
	ea_end = ea_start + extrativesize;
	msg("start:%a, end:%a", ea_start, ea_end);

	char* filepath = ask_file(true, "out.bin", "Input file name to save");
	if (filepath == NULL)
	{
		return;
	}

	FILE* fp = qfopen(filepath, "wb");

	if (fp&&base2file(fp, 0, ea_start, ea_end))
	{
		exmsg("path:%s", filepath);
		msg("base:%a, file:%s, size:%d\n", ea_start, filepath, extrativesize);
		msg("base:%a, size:%d, file:%s\n", ea_start, extrativesize, "qwerh");
		exmsg("base:%a , file:%s", ea_start, filepath);
		exmsg("path:%s", filepath);
		qfclose(fp);
	}
	else
	{
		exmsg("Save to file failed!");
	}
	/*ea_t startaddr = 0;
	ea_t endaddr = 0;
	sval_t extrativesize = 0;
	if (read_selection(&startaddr, &endaddr)) {
		extrativesize = endaddr - startaddr;
	}
	else {
		startaddr = get_screen_ea();
		extrativesize = 0x200;

	}
	bool ret = false;
	ret = askaddr(&startaddr, "Input start addr");
	if (!ret)
	{
		exmsg("Get start addr failed!");
		return;
	}
	ret = asklong(&extrativesize, "Input size");
	if (!ret)
	{
		exmsg("Get extrative size failed!");
		return;

	}
	endaddr = startaddr + extrativesize;


	char* filepath = askfile_c(true, "out.bin", "Input file name to save");
	if (filepath == NULL)
	{
		return;
	}

	FILE* fp = qfopen(filepath, "wb");

	if (fp&&base2file(fp, 0, startaddr, endaddr))
	{
		exmsg("path:%s", filepath);
		msg("base:%a, file:%s, size:%x\n", startaddr, filepath, extrativesize);
		msg("base:%a, size:%x, file:%s\n", startaddr, extrativesize, "qwerh");
		exmsg("base:%a , file:%s", startaddr, filepath);
		exmsg("path:%s", filepath);
	}
	else
	{
		exmsg("Save to file failed!");
		return;
	}
*/
	return;
}

