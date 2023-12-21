#include "frmCourses.h"

// Exit btn
System::Void Courses::frmCourses::btnExit_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

// Select btn
System::Void Courses::frmCourses::btnSelect_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	if (radioBtnSearchCourse->Checked)
	{
		if (courseList->getNumberOfCourses() == 0)
		{
			MessageBox::Show("Database is empty.\nPlease contact the IT Dept.",
				"Search Course");
		}
		else
		{
			Form^ searchForm = gcnew frmSearchCourse(courseList);
			searchForm->ShowDialog();
		}
	}
	else if (radioBtnAddCourse->Checked)
	{
		MessageBox::Show("To add a new course, please contact\nthe Curriculum Committee.",
			"Attention!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
	else if (radioBtnDeleteCourse->Checked)
	{
		if (courseList->getNumberOfCourses() == 0)
			MessageBox::Show("Database is empty.\nPlease contact the IT Dept.",
				"Delete Course");
		else
		{
			Form^ searchForm = gcnew frmDeleteCourse(courseList);
			searchForm->ShowDialog();
		}
	}
	else if (radioBtnDisplayCourses->Checked)
	{
		if (courseList->getNumberOfCourses() == 0)
			MessageBox::Show("Database is empty.\nPlease contact the IT Dept.",
				"Delete Course");
		else
		{
			std::string input; // retrieves the string to display
			courseList->retrieveAllCourses(input);

			String^ str = gcnew String(input.c_str());

			MessageBox::Show(str, "CS Courses");
		}
	}
	else
		MessageBox::Show("Please, make a selection.", "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
}

System::Void Courses::frmCourses::btn_AdvanceMode_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	Form^ displayCourses = gcnew frmDisplayCourses(courseList);
	displayCourses->ShowDialog();
}