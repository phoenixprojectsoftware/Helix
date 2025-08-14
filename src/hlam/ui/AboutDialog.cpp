#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QString>

#include <AL/al.h>

#include "ProjectInfo.hpp"

#include "application/AssetManager.hpp"

// This file is rebuilt whenever the ProjectInfo.hpp header is regenerated so keep it as lightweight as possible.

static QString GetVersionInfo()
{
	return QString{"%1.%2.%3 %4"}
		.arg(HLAMVersionMajor)
		.arg(HLAMVersionMinor)
		.arg(HLAMVersionPatch)
		.arg(HLAMBuildType);
}

static QString GetBuildConfiguration()
{
#ifdef NDEBUG
	return "Release";
#else
	return "Debug";
#endif
}

void LogAppInfo()
{
	qCCritical(HLAM) << QApplication::applicationName() << GetVersionInfo();
	qCCritical(HLAM) << "Build Configuration:" << GetBuildConfiguration();
	qCCritical(HLAM) << "Git Info:"
		<< "\nBranch:" << QString::fromUtf8(HLAMGitBranchName)
		<< "\nTag:" << QString::fromUtf8(HLAMGitTagName)
		<< "\nCommit Hash:" << QString::fromUtf8(HLAMGitCommitHash);
	qCCritical(HLAM) << "Qt Version:" << QT_VERSION_STR;
	qCCritical(HLAM) << "Build Date:" << __DATE__;
}

void ShowAboutDialog(QWidget* parent)
{
	const QString programName{QApplication::applicationName()};

	const auto alVersion = alGetString(AL_VERSION);

	QMessageBox::about(parent, "About " + programName,
		QString::fromUtf8(
			reinterpret_cast<const char*>(u8R"(%1 %2

2025 The Phoenix Project Software SVG

Based on Half-Life Asset Manager v3.0 (c) 2024 Sam Vanheer
Email: sam.vanheer@outlook.com

Based on Jed's Half-Life Model Viewer v1.3 (c) 2004 Neil 'Jed' Jedrzejewski
Email:	jed@wunderboy.org
Web:	http://www.wunderboy.org/

Also based on Half-Life Model Viewer v1.25 (c) 2002 Mete Ciragan
Email:	mete@swissquake.ch
Web:	http://www.milkshape3d.com/

This product contains software technology licensed from Id Software, Inc.
( "Id Technology" ). Id Technology (c) 1996 Id Software, Inc.
All Rights Reserved.

Copyright (c) 1998-2002, Valve LLC.
All rights reserved.

Uses OpenAL Soft (Version %7)
Uses Ogg Vorbis
Uses Libnyquist, Copyright (c) 2019, Dimitri Diakopoulos All rights reserved.
Uses The OpenGL Mathemathics library (GLM)
Copyright (c) 2005 - 2016 G-Truc Creation

Uses Qt %8

Build Date: %9
)"))
			.arg(programName)
			.arg(GetVersionInfo())
			.arg(alVersion)
			.arg(QT_VERSION_STR)
			.arg(__TIMESTAMP__)
);
}
