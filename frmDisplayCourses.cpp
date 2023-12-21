#include "frmDisplayCourses.h"
#include "frmCourses.h"
#include "TestingCases.h"
#include <iostream>
#include <String>
using namespace std;
using namespace System;
using namespace System::Collections::Generic;


// Exit btn
System::Void Courses::frmDisplayCourses::btn_Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
// Load
System::Void Courses::frmDisplayCourses::tableDataCourse(System::Object^ sender, System::EventArgs^ e, Course courseData)
{
	dataGridView1->DataSource = nullptr;
	dataGridView1->Columns->Clear();
	DataTable^ DataTable2 = gcnew DataTable();
	DataTable2->Columns->Add("Id");
	DataTable2->Columns->Add("Course Number");
	DataTable2->Columns->Add("Course Name");
	DataTable2->Columns->Add("Units");
	DataTable2->Columns->Add("Prereqs");

	String^ prereqs = gcnew String("");
	String^ prefix = gcnew String(Course::getPrefix().c_str());
	std::set<int> prerequisites = courseData.getCoursePrereqs();
	if (!prerequisites.empty())
	{
		set<int> prerequisites = courseData.getCoursePrereqs();
		size_t numOfPrereqs = prerequisites.size();
		auto iterSet = prerequisites.begin();
		for (size_t i = 0; i < numOfPrereqs - 1; ++i)
		{
			prereqs += prefix + (*iterSet).ToString() + ", ";
			++iterSet;
		}
	}
	else 
	{
		prereqs += "No prerequisites required.";
	}

	DataRow^ DataRow1;
	DataRow1 = DataTable2->NewRow();
	DataRow1[0] = courseData.getCourseNumber();
	DataRow1[1] = prefix + courseData.getCourseNumber();
	DataRow1[2] = gcnew String(courseData.getCourseName().c_str());
	DataRow1[3] = courseData.getCourseUnits();
	DataRow1[4] = prereqs;

	DataTable2->Rows->Add(DataRow1);
	dataGridView1->DataSource = DataTable2;
	dataGridView1->Columns[0]->Visible = true;
	dataGridView1->Columns[0]->Visible = false;
	dataGridView1->Columns[1]->Width = 120;
	dataGridView1->Columns[2]->Width = 120;
	dataGridView1->Columns[3]->Width = 70;
	dataGridView1->Columns[4]->Width = 148;
	DataGridViewButtonColumn^ deleteButton = gcnew DataGridViewButtonColumn();
	deleteButton->Name = "dataGridViewDeleteButton";
	deleteButton->HeaderText = "Delete";
	deleteButton->Text = "Delete";
	deleteButton->UseColumnTextForButtonValue = true;
	dataGridView1->Columns->Add(deleteButton);
}

System::Void Courses::frmDisplayCourses::frmDisplayCourses_Load(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView1->DataSource = nullptr;
	dataGridView1->Columns->Clear();
	
	if (courseList->getNumberOfCourses() == 0)
		MessageBox::Show("Database is empty.\nPlease contact the IT Dept.",
			"Delete Course");
	else 
	{
		dataGridView1->Refresh();
		DataTable^ DataTable1 = gcnew DataTable();
		DataTable1->Columns->Add("Id");
		DataTable1->Columns->Add("Course Number");
		DataTable1->Columns->Add("Course Name");
		DataTable1->Columns->Add("Units");
		DataTable1->Columns->Add("Prereqs");

		DataRow^ DataRow1;
		Course course;
		for (int i = 100; i < 300; i++)
		{
			if (courseList->searchCourse(i, course))
			{
				String^ prereqs = gcnew String("");
				String^ prefix = gcnew String(Course::getPrefix().c_str());
				set<int> prerequisites = course.getCoursePrereqs();
				if (prerequisites.empty())
				{
					prereqs = "No prerequisites required.";
				}
				else
				{
					size_t numOfPrereqs = prerequisites.size();
					auto iterSet = prerequisites.begin();
					for (size_t i = 0; i < numOfPrereqs - 1; ++i)
					{
						prereqs += prefix + (*iterSet).ToString() + ", ";
						++iterSet;
					}
					prereqs += prefix + (*iterSet).ToString();
				}

				DataRow1 = DataTable1->NewRow();
				DataRow1[0] = course.getCourseNumber();
				DataRow1[1] = prefix + course.getCourseNumber();
				DataRow1[2] = gcnew String(course.getCourseName().c_str());
				DataRow1[3] = course.getCourseUnits();
				DataRow1[4] = prereqs;

				DataTable1->Rows->Add(DataRow1);
			}
		}

		dataGridView1->DataSource = DataTable1;
		dataGridView1->Columns[0]->Visible = false;
		dataGridView1->Columns[1]->Width = 120;
		dataGridView1->Columns[2]->Width = 120;
		dataGridView1->Columns[3]->Width = 70;
		dataGridView1->Columns[4]->Width = 148;

		DataGridViewButtonColumn^ deleteButton = gcnew DataGridViewButtonColumn();
		deleteButton->Name = "dataGridViewDeleteButton";
		deleteButton->HeaderText = "Delete";
		deleteButton->Text = "Delete";
		deleteButton->UseColumnTextForButtonValue = true;
		dataGridView1->Columns->Add(deleteButton);
	}
}

System::Void Courses::frmDisplayCourses::btn_Search_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (IsPresent(txt_Search, "Course Number") &&
		IsInt32(txt_Search, "Course Number") &&
		IsWithinRange(txt_Search, "Course Number", 100, 300))
	{

		int courseNumber = Convert::ToInt32(txt_Search->Text);
		Course course;
		if (courseList->searchCourse(courseNumber, course))
		{
			tableDataCourse(sender, e, course);
		}
		else
		{
			MessageBox::Show("Course Number: " + courseNumber +
				"\n\nThis course is not in the database." +
				"\nTry a different course number.", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
	}

};

System::Void Courses::frmDisplayCourses::btn_ViewAll_Click(System::Object^ sender, System::EventArgs^ e)
{
	txt_Search->Text = "";
	dataGridView1->DataSource = nullptr;
	frmDisplayCourses_Load(sender, e);
}

System::Void Courses::frmDisplayCourses::btn_AddCourse_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("To add a new course, please contact\nthe Curriculum Committee.",
		"Attention!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
}

System::Void Courses::frmDisplayCourses::btn_BasicMode_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	Form^ displayCourses = gcnew frmCourses(courseList);
	displayCourses->ShowDialog();
	

}

System::Void Courses::frmDisplayCourses::dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
		if (e->ColumnIndex == 5 && e->RowIndex != -1)
		{
			String^ s = dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString();
			if (s != "" && s != nullptr)
			{
				int courseNumber = Convert::ToInt32(s);
				if (courseList->searchCourse(courseNumber))
				{
					String^ prefix = gcnew String(Course::getPrefix().c_str());
					System::Windows::Forms::DialogResult result = MessageBox::Show(this, "Do You want to delete " 
						+ prefix + courseNumber + "?", "", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);
					if (System::Windows::Forms::DialogResult::OK == result)
					{
						courseList->deleteCourse(courseNumber);
						dataGridView1->Rows->RemoveAt(e->RowIndex);
					}
				}
				else
				{
					MessageBox::Show("Course Number: " + courseNumber +
						"\n\nThis course is not in the database." +
						"\nTry a different course number.", "Error");
				}

			}
		}
}