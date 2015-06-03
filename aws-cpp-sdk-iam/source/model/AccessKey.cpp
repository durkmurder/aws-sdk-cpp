/*
* Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/iam/model/AccessKey.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::IAM::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

AccessKey::AccessKey() : 
    m_createDate(0.0),
    m_createDateHasBeenSet(false)
{
}

AccessKey::AccessKey(const XmlNode& xmlNode) : 
    m_createDate(0.0),
    m_createDateHasBeenSet(false)
{
  *this = xmlNode;
}

AccessKey& AccessKey::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode userNameNode = resultNode.FirstChild("UserName");
    m_userName = StringUtils::Trim(userNameNode.GetText().c_str());
    XmlNode accessKeyIdNode = resultNode.FirstChild("AccessKeyId");
    m_accessKeyId = StringUtils::Trim(accessKeyIdNode.GetText().c_str());
    XmlNode statusNode = resultNode.FirstChild("Status");
    m_status = statusTypeMapper::GetstatusTypeForName(StringUtils::Trim(statusNode.GetText().c_str()).c_str());
    XmlNode secretAccessKeyNode = resultNode.FirstChild("SecretAccessKey");
    m_secretAccessKey = StringUtils::Trim(secretAccessKeyNode.GetText().c_str());
    XmlNode createDateNode = resultNode.FirstChild("CreateDate");
    if(!createDateNode.IsNull())
    {
      m_createDate = StringUtils::ConvertToDouble(StringUtils::Trim(createDateNode.GetText().c_str()).c_str());
      m_createDateHasBeenSet = true;
    }
  }

  return *this;
}

void AccessKey::OutputToStream(Aws::OStream& oStream, const char* location, unsigned index, const char* locationValue) const
{
  oStream << location << index << locationValue << ".UserName=" << StringUtils::URLEncode(m_userName.c_str()) << "&";
  oStream << location << index << locationValue << ".AccessKeyId=" << StringUtils::URLEncode(m_accessKeyId.c_str()) << "&";
  oStream << location << index << locationValue << ".Status=" << statusTypeMapper::GetNameForstatusType(m_status) << "&";
  oStream << location << index << locationValue << ".SecretAccessKey=" << StringUtils::URLEncode(m_secretAccessKey.c_str()) << "&";
  if(m_createDateHasBeenSet)
  {
      oStream << location << index << locationValue << ".CreateDate=" << m_createDate << "&";
  }
}

void AccessKey::OutputToStream(Aws::OStream& oStream, const char* location) const
{
  oStream << location << ".UserName=" << StringUtils::URLEncode(m_userName.c_str()) << "&";
  oStream << location << ".AccessKeyId=" << StringUtils::URLEncode(m_accessKeyId.c_str()) << "&";
  oStream << location << ".Status=" << statusTypeMapper::GetNameForstatusType(m_status) << "&";
  oStream << location << ".SecretAccessKey=" << StringUtils::URLEncode(m_secretAccessKey.c_str()) << "&";
  if(m_createDateHasBeenSet)
  {
      oStream << location << ".CreateDate=" << m_createDate << "&";
  }
}