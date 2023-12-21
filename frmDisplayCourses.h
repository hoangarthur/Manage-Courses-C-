#pragma once

#include "CourseList.h"

namespace Courses {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmDisplayCourses
	/// </summary>
	public ref class frmDisplayCourses : public System::Windows::Forms::Form
	{
	public:
		frmDisplayCourses(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		frmDisplayCourses(CourseList* list)
		{
			InitializeComponent();
			courseList = list;
		}
	private: System::Windows::Forms::Button^ btn_AddCourse;
	private: System::Windows::Forms::Button^ btn_BasicMode;
	private: System::Windows::Forms::Button^ btn_Exit;
	private: System::Windows::Forms::Label^ label1;


	public:

		CourseList* courseList;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmDisplayCourses()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ btn_Search;
	private: System::Windows::Forms::TextBox^ txt_Search;
	private: System::Windows::Forms::Button^ btn_ViewAll;


	protected:

	protected:






	protected:






	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btn_Search = (gcnew System::Windows::Forms::Button());
			this->txt_Search = (gcnew System::Windows::Forms::TextBox());
			this->btn_ViewAll = (gcnew System::Windows::Forms::Button());
			this->btn_AddCourse = (gcnew System::Windows::Forms::Button());
			this->btn_BasicMode = (gcnew System::Windows::Forms::Button());
			this->btn_Exit = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 98);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(619, 273);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmDisplayCourses::dataGridView1_CellClick);
			// 
			// btn_Search
			// 
			this->btn_Search->Location = System::Drawing::Point(205, 69);
			this->btn_Search->Name = L"btn_Search";
			this->btn_Search->Size = System::Drawing::Size(75, 23);
			this->btn_Search->TabIndex = 1;
			this->btn_Search->Text = L"Search";
			this->btn_Search->UseVisualStyleBackColor = true;
			this->btn_Search->Click += gcnew System::EventHandler(this, &frmDisplayCourses::btn_Search_Click);
			// 
			// txt_Search
			// 
			this->txt_Search->Location = System::Drawing::Point(12, 71);
			this->txt_Search->Name = L"txt_Search";
			this->txt_Search->Size = System::Drawing::Size(187, 20);
			this->txt_Search->TabIndex = 2;
			// 
			// btn_ViewAll
			// 
			this->btn_ViewAll->Location = System::Drawing::Point(515, 69);
			this->btn_ViewAll->Name = L"btn_ViewAll";
			this->btn_ViewAll->Size = System::Drawing::Size(116, 23);
			this->btn_ViewAll->TabIndex = 3;
			this->btn_ViewAll->Text = L"View All Course";
			this->btn_ViewAll->UseVisualStyleBackColor = true;
			this->btn_ViewAll->Click += gcnew System::EventHandler(this, &frmDisplayCourses::btn_ViewAll_Click);
			// 
			// btn_AddCourse
			// 
			this->btn_AddCourse->Location = System::Drawing::Point(286, 69);
			this->btn_AddCourse->Name = L"btn_AddCourse";
			this->btn_AddCourse->Size = System::Drawing::Size(75, 23);
			this->btn_AddCourse->TabIndex = 5;
			this->btn_AddCourse->Text = L"Add Course";
			this->btn_AddCourse->UseVisualStyleBackColor = true;
			this->btn_AddCourse->Click += gcnew System::EventHandler(this, &frmDisplayCourses::btn_AddCourse_Click);
			// 
			// btn_BasicMode
			// 
			this->btn_BasicMode->Location = System::Drawing::Point(12, 12);
			this->btn_BasicMode->Name = L"btn_BasicMode";
			this->btn_BasicMode->Size = System::Drawing::Size(75, 23);
			this->btn_BasicMode->TabIndex = 6;
			this->btn_BasicMode->Text = L"Basic Mode";
			this->btn_BasicMode->UseVisualStyleBackColor = true;
			this->btn_BasicMode->Click += gcnew System::EventHandler(this, &frmDisplayCourses::btn_BasicMode_Click);
			// 
			// btn_Exit
			// 
			this->btn_Exit->Location = System::Drawing::Point(556, 12);
			this->btn_Exit->Name = L"btn_Exit";
			this->btn_Exit->Size = System::Drawing::Size(75, 23);
			this->btn_Exit->TabIndex = 7;
			this->btn_Exit->Text = L"Exit";
			this->btn_Exit->UseVisualStyleBackColor = true;
			this->btn_Exit->Click += gcnew System::EventHandler(this, &frmDisplayCourses::btn_Exit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(231, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Please, enter a course number (i.e., 131, 140...)";
			// 
			// frmDisplayCourses
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(644, 382);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_Exit);
			this->Controls->Add(this->btn_BasicMode);
			this->Controls->Add(this->btn_AddCourse);
			this->Controls->Add(this->btn_ViewAll);
			this->Controls->Add(this->txt_Search);
			this->Controls->Add(this->btn_Search);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"frmDisplayCourses";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CS Courses";
			this->Load += gcnew System::EventHandler(this, &frmDisplayCourses::frmDisplayCourses_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:

		System::Void frmDisplayCourses_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_Search_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_ViewAll_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_AddCourse_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_BasicMode_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_Exit_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Courses::frmDisplayCourses::tableDataCourse(System::Object^ sender, System::EventArgs^ e, Course);
		System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		private: bool IsPresent(TextBox^ textBox, String^ name)
		{
			if (textBox->Text == "")
			{
				MessageBox::Show(name + " is a required field.", "Entry Error");
				textBox->Focus();
				return false;
			}
			return true;
		}

			   // Validator: Text is integer
		private: bool IsInt32(TextBox^ textBox, String^ name)
		{
			try
			{
				Convert::ToInt32(textBox->Text);
				return true;
			}
			catch (FormatException^)
			{
				MessageBox::Show(name + " must be a valid integer.", "Entry Error");
				textBox->Focus();
				return false;
			}
		}

			   // Validator: Text is within range
		private: bool IsWithinRange(TextBox^ textBox, String^ name,
			double min, double max)
		{
			double number = Convert::ToDouble(textBox->Text);
			if (number < min || number > max)
			{
				MessageBox::Show(name + " must be between " + min +
					" and " + max + ".", "Entry Error");
				textBox->Focus();
				return false;
			}
			return true;
		}
};
}
