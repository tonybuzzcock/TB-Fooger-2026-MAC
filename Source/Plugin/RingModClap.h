// RingModClap.h
// The three entry functions clap-wrapper links into every format.

#pragma once

bool tbfooger_entry_init (const char* pluginPath);
void tbfooger_entry_deinit();
const void* tbfooger_entry_get_factory (const char* factoryId);
