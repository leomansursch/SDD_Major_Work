#pragma once
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "GUI.cpp"
namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ startbool;
	protected:

	private: System::Windows::Forms::CheckBox^ portsbool;
	private: System::Windows::Forms::CheckBox^ odirbool;
	protected:


	private: System::Windows::Forms::TextBox^ Hosttxt;
	private: System::Windows::Forms::TextBox^ porttxt;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ odir;


	private: System::Windows::Forms::Label^ output;

	private: System::Windows::Forms::Label^ label5;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->startbool = (gcnew System::Windows::Forms::Button());
			this->portsbool = (gcnew System::Windows::Forms::CheckBox());
			this->odirbool = (gcnew System::Windows::Forms::CheckBox());
			this->Hosttxt = (gcnew System::Windows::Forms::TextBox());
			this->porttxt = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->odir = (gcnew System::Windows::Forms::TextBox());
			this->output = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// startbool
			// 
			this->startbool->Location = System::Drawing::Point(431, 375);
			this->startbool->Name = L"startbool";
			this->startbool->Size = System::Drawing::Size(75, 32);
			this->startbool->TabIndex = 0;
			this->startbool->Text = L"Start";
			this->startbool->UseVisualStyleBackColor = true;
			this->startbool->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// portsbool
			// 
			this->portsbool->AutoSize = true;
			this->portsbool->Location = System::Drawing::Point(61, 155);
			this->portsbool->Name = L"portsbool";
			this->portsbool->Size = System::Drawing::Size(155, 21);
			this->portsbool->TabIndex = 1;
			this->portsbool->Text = L"Scan for open ports";
			this->portsbool->UseVisualStyleBackColor = true;
			this->portsbool->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// odirbool
			// 
			this->odirbool->AutoSize = true;
			this->odirbool->Location = System::Drawing::Point(61, 222);
			this->odirbool->Name = L"odirbool";
			this->odirbool->Size = System::Drawing::Size(209, 21);
			this->odirbool->TabIndex = 2;
			this->odirbool->Text = L"Output to a custom directory";
			this->odirbool->UseVisualStyleBackColor = true;
			this->odirbool->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			// 
			// Hosttxt
			// 
			this->Hosttxt->Location = System::Drawing::Point(61, 71);
			this->Hosttxt->Name = L"Hosttxt";
			this->Hosttxt->Size = System::Drawing::Size(100, 22);
			this->Hosttxt->TabIndex = 3;
			this->Hosttxt->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// porttxt
			// 
			this->porttxt->Location = System::Drawing::Point(61, 182);
			this->porttxt->Name = L"porttxt";
			this->porttxt->Size = System::Drawing::Size(100, 22);
			this->porttxt->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(58, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 17);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Host";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(58, 135);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(290, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Enter ports separated by a comma (optional)";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(58, 246);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(145, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Enter output directory";
			// 
			// odir
			// 
			this->odir->Location = System::Drawing::Point(61, 266);
			this->odir->Name = L"odir";
			this->odir->Size = System::Drawing::Size(100, 22);
			this->odir->TabIndex = 7;
			// 
			// output
			// 
			this->output->AutoSize = true;
			this->output->Location = System::Drawing::Point(568, 76);
			this->output->Name = L"output";
			this->output->Size = System::Drawing::Size(162, 17);
			this->output->TabIndex = 10;
			this->output->Text = L"Awating program start ...";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(571, 50);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 17);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Output";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(759, 446);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->output);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->odir);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->porttxt);
			this->Controls->Add(this->Hosttxt);
			this->Controls->Add(this->odirbool);
			this->Controls->Add(this->portsbool);
			this->Controls->Add(this->startbool);
			this->Name = L"MyForm";
			this->Text = L"GUI - SDD_Major_Work - Leo Mansur";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ hosts = Hosttxt->Text;
	String^ ports = porttxt->Text;
	String^ fout = odir->Text;
	extern std::string tmp2;
	extern bool useport, uout;
	extern std::string host, fileoutput;
	useport = portsbool->Checked;
	uout = odirbool->Checked;
	std::string host1 = msclr::interop::marshal_as<std::string>(hosts);
	std::string tmp21 = msclr::interop::marshal_as<std::string>(ports);
	std::string fileoutput1 = msclr::interop::marshal_as<std::string>(fout);
	fileoutput = fileoutput1;
	tmp2 = tmp21;
	host = host1;



}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
