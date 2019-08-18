#ifndef NPP_PYSCRIPT_CORE_IMPORTEXPORT_H_GUARD
#define NPP_PYSCRIPT_CORE_IMPORTEXPORT_H_GUARD

#ifdef _WIN32
	#ifdef NPP_STANDALONE
			#define NPP_PYSCRIPT_CORE_API
	#else
		#ifdef NPP_PYSCRIPT_CORE_EXPORTS
			#define NPP_PYSCRIPT_CORE_API	__declspec(dllexport)
		#else
			#define NPP_PYSCRIPT_CORE_API	__declspec(dllimport)
		#endif
	#endif
#endif


#endif // NPP_PYSCRIPT_CORE_IMPORTEXPORT_H_GUARD