// Copyright (C) Explorer++ Project
// SPDX-License-Identifier: GPL-3.0-only
// See LICENSE in the top level directory

#include "pch.h"
#include "ColorRuleXmlStorage.h"
#include "ColorRuleModel.h"
#include "ColorRulesStorageHelper.h"
#include "MovableModelHelper.h"
#include "ResourceHelper.h"
#include "XmlStorageHelper.h"
#include <gtest/gtest.h>

using namespace testing;

class ColorRuleXmlStorageTest : public XmlStorageTest
{
};

TEST_F(ColorRuleXmlStorageTest, Load)
{
	ColorRuleModel referenceModel;
	BuildLoadSaveReferenceModel(&referenceModel);

	std::wstring xmlFilePath = GetResourcePath(L"color-rules-config.xml");
	auto xmlDocument = LoadXmlDocument(xmlFilePath);
	ASSERT_TRUE(xmlDocument);

	ColorRuleModel loadedModel;
	ColorRuleXmlStorage::Load(xmlDocument.get(), &loadedModel);

	EXPECT_EQ(loadedModel, referenceModel);
}

TEST_F(ColorRuleXmlStorageTest, Save)
{
	ColorRuleModel referenceModel;
	BuildLoadSaveReferenceModel(&referenceModel);

	auto xmlDocumentData = CreateXmlDocument();
	ASSERT_TRUE(xmlDocumentData);

	ColorRuleXmlStorage::Save(xmlDocumentData->xmlDocument.get(), xmlDocumentData->root.get(),
		&referenceModel);

	ColorRuleModel loadedModel;
	ColorRuleXmlStorage::Load(xmlDocumentData->xmlDocument.get(), &loadedModel);

	EXPECT_EQ(loadedModel, referenceModel);
}
