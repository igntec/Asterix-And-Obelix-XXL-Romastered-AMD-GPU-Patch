#include <windows.h>
#include <string>
#include <fstream>

bool g_fire, g_dust_trail, g_collectables, g_gold, g_hits;

typedef void(__stdcall *glProgramBinary_type)(unsigned int, int, void*, size_t);

glProgramBinary_type glProgramBinary_real;

void __stdcall My_glProgramBinary(unsigned int program, int format, void *binary, size_t len)
{
	glProgramBinary_real(0, format, binary, len);
}

void* Hook_glProgramBinary(void *real)
{
	glProgramBinary_real = (glProgramBinary_type)real;
	return My_glProgramBinary;
}

typedef void(__stdcall *glShaderSource_type)(unsigned int, size_t, const char**, int*);

glShaderSource_type glShaderSource_real;

void __stdcall My_glShaderSource(unsigned int shader, size_t count, const char **strings, int *len)
{
	std::string src_shader;

	if (len)
	{
		for (size_t i = 0; i < count; i++)
		{
			if (len[i] >= 0)
			{
				char *p = new char[len[i] + 1];
				memcpy(p, strings[i], len[i]);
				p[len[i]] = 0;
				src_shader += p;
				delete[] p;
			}
			else
				src_shader += strings[i];
		}
	}
	else
	{
		for (size_t i = 0; i < count; i++)
			src_shader += strings[i];
	}

	size_t hash_shader = std::hash<std::string>{}(src_shader);
	bool fix_implemented = false;

	if (hash_shader == 1913522247)
	{
		fix_implemented = true;
		g_fire = true;
	}
	else if (hash_shader == 1806600576)
	{
		fix_implemented = true;
		g_dust_trail = true;
	}
	else if (hash_shader == 240415027)
	{
		fix_implemented = true;
		g_collectables = true;
	}
	else if (hash_shader == 3760941141)
	{
		fix_implemented = true;
		g_gold = true;
	}
	else if (hash_shader == 792715368)
	{
		fix_implemented = true;
		g_hits = true;
	}

	if (fix_implemented)
	{
		std::string path_shader = "shaders/" + std::to_string(hash_shader) + ".txt";
		std::ifstream file_shader(path_shader);
		std::string line_shader;

		src_shader = "";
		while (std::getline(file_shader, line_shader))
			src_shader += line_shader + "\n";

		const char *strings = src_shader.c_str();
		glShaderSource_real(shader, 1, &strings, NULL);
	}
	else
	{
		glShaderSource_real(shader, count, strings, len);
	}
}

void* Hook_glShaderSource(void *real)
{
	glShaderSource_real = (glShaderSource_type)real;
	return My_glShaderSource;
}

bool dll_no_longer_needed()
{
	return g_fire && g_dust_trail && g_collectables && g_gold && g_hits;
}
