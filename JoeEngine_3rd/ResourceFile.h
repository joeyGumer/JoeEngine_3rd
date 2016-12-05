#ifndef __RESOURCEFILE_H__
#define __RESOURCEFILE_H__

#include <string>

enum ResourceFileType
{
	RES_MESH,
	RES_TEXTURE
};

class ResourceFile
{
public:
	ResourceFile(ResourceFileType type, const std::string& file_path, unsigned int uuid);
	~ResourceFile();

	const char* GetFile()const;
	unsigned int GetUUID()const;
	ResourceFileType GetType()const;
	void Load();
	void Unload();
	void UnLoadAll();
	void Reload();

private:
	virtual void LoadInMemory();
	virtual void UnloadInMemory();

protected:
	unsigned int used = 0;
	ResourceFileType type;
	std::string file_path;
	unsigned int uuid = 0;

};

#endif // !__RESOURCEFILE_H__
