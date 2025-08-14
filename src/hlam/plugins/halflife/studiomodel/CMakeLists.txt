target_sources(Helix
	PRIVATE
		StudioModelAsset.cpp
		StudioModelAsset.hpp
		StudioModelAssetProvider.cpp
		StudioModelAssetProvider.hpp
		StudioModelColors.hpp)

add_subdirectory(options)
add_subdirectory(settings)
add_subdirectory(ui)
