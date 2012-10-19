/*
 * AudioManager.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "AudioManager.h"
using namespace CocosDenshion;

static AudioManager *m_Instance;

AudioManager::AudioManager()
{

}

AudioManager* AudioManager::sharedAudioManager()
{
	if (m_Instance == 0)
		m_Instance = new AudioManager();
	return m_Instance;

}

bool AudioManager::IsEnableBackground()
{
	return m_bEnableBackground;
}


bool AudioManager::IsEnableEffect()
{
	return m_bEnableEffect;
}


void AudioManager::SetEnableBackground(bool b)
{
	m_bEnableBackground = b;
}


void AudioManager::SetEnableEffect(bool b)
{
	m_bEnableEffect = b;
}


void AudioManager::LoadBackground(char* path)
{
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(path);
}


void AudioManager::PlayBackground(char* path, bool loop)
{
	if (m_bEnableBackground)
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(path, loop);
}


void AudioManager::PlayEffect(char *path, int loopTime = 0)
{
	if (m_bEnableEffect)
		SimpleAudioEngine::sharedEngine()->playEffect(path, loopTime);
}

