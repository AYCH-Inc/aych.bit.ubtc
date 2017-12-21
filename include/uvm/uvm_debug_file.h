#ifndef uvm_debug_file_h
#define uvm_debug_file_h

#include <uvm/lprefix.h>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>


namespace uvm {
	namespace lua {
		namespace core {


			// .ldb�ļ��е����ݵ����ݽṹ
			class LuaDebugFileInfo
			{
			private:
				std::map<size_t, size_t> _source_line_mappings; // uvmԴ�ļ���lua�м��ļ���line��Ϣ��ӳ���ϵ,������Ҫ����
				std::vector<std::string> _proto_names; // ������ȱ���������˳�����е�proto�����ƣ����������ÿ��ַ���
			public:
				LuaDebugFileInfo();
				LuaDebugFileInfo(const LuaDebugFileInfo &other);
				std::string serialize() const;
				void serialize_to_file(FILE *file) const;
				static LuaDebugFileInfo deserialize(const std::string &content);
				static LuaDebugFileInfo deserialize_from_file(FILE *file);

				void set_source_line_mapping(size_t uvm_line, size_t lua_line);
				void add_proto_name(const std::string &proto_name);

				size_t find_uvm_line_by_lua_line(size_t lua_line);
				size_t find_lua_line_by_uvm_line(size_t uvm_line);
			};

		} // end namespace
	}
}

#endif