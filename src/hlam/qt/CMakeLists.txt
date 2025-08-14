target_sources(Helix
	PRIVATE
		ByteLengthValidator.hpp
		HashFunctions.hpp
		ObservableList.hpp
		QtLogging.hpp
		QtLogSink.hpp
		QtUtilities.cpp
		QtUtilities.hpp)

add_subdirectory(widgets)
