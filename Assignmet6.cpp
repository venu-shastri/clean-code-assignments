#include <string>
#include <vector>

class DocumentPart
{
  private:
  std::wstring Text;

  public:
  std::wstring getText() const;
  void setText(const std::wstring &value);
  virtual std::wstring ToHTML() = 0;
  virtual std::wstring ToPlainText() = 0;
  virtual std::wstring ToLatex() = 0;
};

class PlainText : public DocumentPart
{
  public:
  std::wstring ToHTML() override;
  std::wstring ToPlainText() override;
  std::wstring ToLatex() override;
};

class BoldText : public DocumentPart
{
  public:
  std::wstring ToHTML() override;
  std::wstring ToPlainText() override;
  std::wstring ToLatex() override;
};

class Hyperlink : public DocumentPart
{
  private:
  std::wstring Url;

  public:
  std::wstring getUrl() const;
  void setUrl(const std::wstring &value);

  std::wstring ToHTML() override;
  std::wstring ToPlainText() override;
  std::wstring ToLatex() override;
};

class Document
{
  private:
  std::vector<DocumentPart*> m_parts;

  public:
  std::wstring ToHTML();

  std::wstring ToPlainText();

  std::wstring ToLatex();
};


std::wstring DocumentPart::getText() const
{
	return Text;
}

void DocumentPart::setText(const std::wstring &value)
{
	Text = value;
}

std::wstring PlainText::ToHTML()
{
  return this->getText();
}

std::wstring PlainText::ToPlainText()
{
  return this->getText();
}

std::wstring PlainText::ToLatex()
{
  return this->getText();
}

std::wstring BoldText::ToHTML()
{
  return L"<b>" + this->getText() + L"</b>";
}

std::wstring BoldText::ToPlainText()
{
  return L"**" + this->getText() + L"**";
}

std::wstring BoldText::ToLatex()
{
  return L"\\textbf{" + this->getText() + L"}";
}

std::wstring Hyperlink::getUrl() const
{
	return Url;
}

void Hyperlink::setUrl(const std::wstring &value)
{
	Url = value;
}

std::wstring Hyperlink::ToHTML()
{
  return L"<a href=\"" + this->getUrl() + L"\">" + this->getText() + L"</a>";
}

std::wstring Hyperlink::ToPlainText()
{
  return this->getText() + L" [" + this->getUrl() + L"]";
}

std::wstring Hyperlink::ToLatex()
{
  return L"\\href{" + this->getUrl() + L"}{" + this->getText() + L"}";
}

std::wstring Document::ToHTML()
{
  std::wstring output = L"";
  for (auto part : *this->m_parts)
  {
	output += part->ToHTML();
  }
  return output;
}

std::wstring Document::ToPlainText()
{
  std::wstring output = L"";
  for (auto part : *this->m_parts)
  {
	output += part->ToPlainText();
  }
  return output;
}

std::wstring Document::ToLatex()
{
  std::wstring output = L"";
  for (auto part : *this->m_parts)
  {
	output += part->ToLatex();
  }
  return output;
}
