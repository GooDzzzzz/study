#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb; // для работ с бд


[STAThreadAttribute] // запуск мейна в отдельном потоке данных
int main(array<String^>^ args) // "^" - автоматическая очистка памяти
{

	Application::SetCompatibleTextRenderingDefault(false); // для корректной обработки текста
	Application::EnableVisualStyles(); // подключаем различные визуальные стили

	iz::MyForm form; // создали форму
	Application::Run(% form); // передаем по ссылке обьект form (класс по ссылке ref)

}
//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::button_download_Click(System::Object^ sender, System::EventArgs^ e)
{
	// подключаемся к бд
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";//подключение
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// запрос к бд
	dbConnection->Open();// открываем соединение
	String^ query = "SELECT * FROM [Product]";// запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);// команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();// считываем данные

	// проверяем данные
	if (dbReader->HasRows == false) {
		MessageBox::Show("Ошибка чтения данных!", "Ошибка!");
	}
	else {
		// заполняем таблицу формы данными
		while (dbReader->Read()) {
			dataGridView1->Rows->Add(dbReader["id"], dbReader["Name"], dbReader["Price"]);
		}
	}

	// заакрываем соединение
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::button_add_Click(System::Object^ sender, System::EventArgs^ e)
{
	// выбор нужной строки для добавления
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите ОДНУ строку!", "Внимание!");
		return;
	}

	// узнаем индекс выбранной строки
	int index = dataGridView1->SelectedRows[0]->Index;

	// проверка данных
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr) {
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	// считываем данные
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ price = dataGridView1->Rows[index]->Cells[2]->Value->ToString();

	// подключаемся к бд
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// запрос к бд
	dbConnection->Open();// открываем соединение
	String^ query = "INSERT INTO [Product] VALUES (" + id + ", '" + name + "', " + price + ")";
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);// команда

	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка запроса!", "Ошибка!");
	else
		MessageBox::Show("Данные добавлены!", "Готово!");

	// закрываем соединение
	dbConnection->Close();

	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::button_update_Click(System::Object^ sender, System::EventArgs^ e)
{
	// выбор нужной строки для обновления
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите ОДНУ строку!", "Внимание!");
		return;
	}

	// узнаем индекс выбранной строки
	int index = dataGridView1->SelectedRows[0]->Index;

	// проверка данных
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr) {
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	// считываем данные
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ price = dataGridView1->Rows[index]->Cells[2]->Value->ToString();

	// подключаемся к бд
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// запрос к бд
	dbConnection->Open();// открываем соединение
	String^ query = "UPDATE [Product] SET Name='" + name + "', Price=" + price + " WHERE id = " + id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);// команда

	// выполняем запрос
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка запроса!", "Ошибка!");
	else
		MessageBox::Show("Данные обновлены!", "Готово!");

	// закрываем соединение
	dbConnection->Close();

	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::button_delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	// выбор нужной строки для обновления
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите ОДНУ строку!", "Внимание!");
		return;
	}

	// узнаем индекс выбранной строки
	int index = dataGridView1->SelectedRows[0]->Index;

	// проверка данных
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr)
	{
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	// считываем данные
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();

	// подключаемся к бд
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// запрос к бд
	dbConnection->Open();// открываем соединение
	String^ query = "DELETE FROM [Product] WHERE id = " + id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);// команда

	// выполняем запрос
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка запроса!", "Ошибка!");
	else
	{
		dataGridView1->Rows->RemoveAt(index);
		MessageBox::Show("Данные удалены!", "Готово!");
	}
	// закрываем соединение
	dbConnection->Close();

	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::reboot1_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView1->Rows->Clear();

	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::button_download2_Click(System::Object^ sender, System::EventArgs^ e)
{
	// подключаемся к бд
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";//подключение
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// запрос к бд
	dbConnection->Open();// открываем соединение
	String^ query = "SELECT * FROM [Stock]";// запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);// команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();// считываем данные

	// проверяем данные
	if (dbReader->HasRows == false) {
		MessageBox::Show("Ошибка чтения данных!", "Ошибка!");
	}
	else {
		// заполняем таблицу формы данными
		while (dbReader->Read()) {
			dataGridView2->Rows->Add(dbReader["id"], dbReader["Adress"], dbReader["Volume"]);
		}
	}

	// заакрываем соединение
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::button_add2_Click(System::Object^ sender, System::EventArgs^ e)
{
	// выбор нужной строки для добавления
	if (dataGridView2->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите ОДНУ строку!", "Внимание!");
		return;
	}

	// узнаем индекс выбранной строки
	int index = dataGridView2->SelectedRows[0]->Index;

	// проверка данных
	if (dataGridView2->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView2->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView2->Rows[index]->Cells[2]->Value == nullptr) {
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	// считываем данные
	String^ id = dataGridView2->Rows[index]->Cells[0]->Value->ToString();
	String^ adress = dataGridView2->Rows[index]->Cells[1]->Value->ToString();
	String^ volume = dataGridView2->Rows[index]->Cells[2]->Value->ToString();

	// подключаемся к бд
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// запрос к бд
	dbConnection->Open();// открываем соединение
	String^ query = "INSERT INTO [Stock] VALUES (" + id + ", '" + adress + "', " + volume + ")";
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);// команда

	// выполняем запрос
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка запроса!", "Ошибка!");
	else
		MessageBox::Show("Данные добавлены!", "Готово!");

	// закрываем соединение
	dbConnection->Close();

	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::button_update2_Click(System::Object^ sender, System::EventArgs^ e)
{
	// выбор нужной строки для добавления
	if (dataGridView2->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите ОДНУ строку!", "Внимание!");
		return;
	}

	// узнаем индекс выбранной строки
	int index = dataGridView2->SelectedRows[0]->Index;

	// проверка данных
	if (dataGridView2->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView2->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView2->Rows[index]->Cells[2]->Value == nullptr) {
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	// считываем данные
	String^ id = dataGridView2->Rows[index]->Cells[0]->Value->ToString();
	String^ adress = dataGridView2->Rows[index]->Cells[1]->Value->ToString();
	String^ volume = dataGridView2->Rows[index]->Cells[2]->Value->ToString();

	// подключаемся к бд
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// запрос к бд
	dbConnection->Open();// открываем соединение
	String^ query = "UPDATE [Stock] SET Adress='" + adress + "', Volume = " + volume + " WHERE id = " + id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);// команда

	// выполняем запрос
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка запроса!", "Ошибка!");
	else
		MessageBox::Show("Данные обновлены!", "Готово!");

	// закрываем соединение
	dbConnection->Close();

	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::button_delete2_Click(System::Object^ sender, System::EventArgs^ e)
{
	// выбор нужной строки для обновления
	if (dataGridView2->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите ОДНУ строку!", "Внимание!");
		return;
	}

	// узнаем индекс выбранной строки
	int index = dataGridView2->SelectedRows[0]->Index;

	// проверка данных
	if (dataGridView2->Rows[index]->Cells[0]->Value == nullptr)
	{
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	// считываем данные
	String^ id = dataGridView2->Rows[index]->Cells[0]->Value->ToString();

	// подключаемся к бд
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// запрос к бд
	dbConnection->Open();// открываем соединение
	String^ query = "DELETE FROM [Stock] WHERE id = " + id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);// команда

	// выполняем запрос
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка запроса!", "Ошибка!");
	else
	{
		dataGridView2->Rows->RemoveAt(index);
		MessageBox::Show("Данные удалены!", "Готово!");
	}
	// закрываем соединение
	dbConnection->Close();

	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::reboot2_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView2->Rows->Clear();

	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::download3_Click(System::Object^ sender, System::EventArgs^ e)
{
	// подключаемся к бд
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";//подключение
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// запрос к бд
	dbConnection->Open();// открываем соединение
	String^ query = "SELECT * FROM [Zakaz]";// запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);// команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();// считываем данные

	// проверяем данные
	if (dbReader->HasRows == false) {
		MessageBox::Show("Ошибка чтения данных!", "Ошибка!");
	}
	else {
		// заполняем таблицу формы данными
		while (dbReader->Read()) {
			dataGridView4->Rows->Add(dbReader["id"], dbReader["id_Product"], dbReader["id_Stock"], dbReader["Count"]);
		}
	}

	// заакрываем соединение
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::add3_Click(System::Object^ sender, System::EventArgs^ e)
{
	// выбор нужной строки для добавления
	if (dataGridView4->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите ОДНУ строку!", "Внимание!");
		return;
	}

	// узнаем индекс выбранной строки
	int index = dataGridView4->SelectedRows[0]->Index;

	// проверка данных
	if (dataGridView4->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView4->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView4->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView4->Rows[index]->Cells[3]->Value == nullptr) {
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	// считываем данные
	String^ id = dataGridView4->Rows[index]->Cells[0]->Value->ToString();
	String^ id_Product = dataGridView4->Rows[index]->Cells[1]->Value->ToString();
	String^ id_Stock = dataGridView4->Rows[index]->Cells[2]->Value->ToString();
	String^ Count = dataGridView4->Rows[index]->Cells[3]->Value->ToString();

	// подключаемся к бд
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// запрос к бд
	dbConnection->Open();// открываем соединение
	String^ query = "INSERT INTO [Zakaz] VALUES (" + id + ", " + id_Product + ", " + id_Stock + ", " + Count + ")";
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);// команда

	// выполняем запрос
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка запроса!", "Ошибка!");
	else
		MessageBox::Show("Данные добавлены!", "Готово!");

	// закрываем соединение
	dbConnection->Close();

	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::update3_Click(System::Object^ sender, System::EventArgs^ e)
{
	// выбор нужной строки для добавления
	if (dataGridView4->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите ОДНУ строку!", "Внимание!");
		return;
	}

	// узнаем индекс выбранной строки
	int index = dataGridView4->SelectedRows[0]->Index;

	// проверка данных
	if (dataGridView4->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView4->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView4->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView4->Rows[index]->Cells[3]->Value == nullptr) {
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	// считываем данные
	String^ id = dataGridView4->Rows[index]->Cells[0]->Value->ToString();
	String^ idproduct = dataGridView4->Rows[index]->Cells[1]->Value->ToString();
	String^ idstock = dataGridView4->Rows[index]->Cells[2]->Value->ToString();
	String^ count = dataGridView4->Rows[index]->Cells[3]->Value->ToString();

	// подключаемся к бд
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// запрос к бд
	dbConnection->Open();// открываем соединение
	String^ query = "UPDATE [Zakaz] SET id_Product =" + idproduct + ", id_Stock =" + idstock + ", Count =" + count + " WHERE id = " + id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);// команда

	// выполняем запрос
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка запроса!", "Ошибка!");
	else
		MessageBox::Show("Данные добавлены!", "Готово!");

	// закрываем соединение
	dbConnection->Close();

	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::delete3_Click(System::Object^ sender, System::EventArgs^ e)
{
	// выбор нужной строки для обновления
	if (dataGridView4->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите ОДНУ строку!", "Внимание!");
		return;
	}

	// узнаем индекс выбранной строки
	int index = dataGridView4->SelectedRows[0]->Index;

	// проверка данных
	if (dataGridView4->Rows[index]->Cells[0]->Value == nullptr)
	{
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	// считываем данные
	String^ id = dataGridView4->Rows[index]->Cells[0]->Value->ToString();

	// подключаемся к бд
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// запрос к бд
	dbConnection->Open();// открываем соединение
	String^ query = "DELETE FROM [Zakaz] WHERE id = " + id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);// команда

	// выполняем запрос
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка запроса!", "Ошибка!");
	else
	{
		dataGridView4->Rows->RemoveAt(index);
		MessageBox::Show("Данные удалены!", "Готово!");
	}
	// закрываем соединение
	dbConnection->Close();

	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::reboot3_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView4->Rows->Clear();

	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::button_search_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox_search_product->Text == "" || textBox_search_stock->Text == "") {
		MessageBox::Show("Недостаточно данных!", "Внимание!");
		return;
	}

	int rowCount = dataGridView4->RowCount;
	int count_find = 0;

	for (int i = 0; i < rowCount - 1; i++)
	{
		if ((productText == dataGridView4->Rows[i]->Cells[1]->Value->ToString()) && (stockText == dataGridView4->Rows[i]->Cells[2]->Value->ToString()))
		{
			String^ cellValue1 = dataGridView4->Rows[i]->Cells[0]->Value->ToString();
			String^ cellValue2 = dataGridView4->Rows[i]->Cells[1]->Value->ToString();
			String^ cellValue3 = dataGridView4->Rows[i]->Cells[2]->Value->ToString();
			String^ cellValue4 = dataGridView4->Rows[i]->Cells[3]->Value->ToString();

			dataGridView3->Rows->Add(cellValue1, cellValue2, cellValue3, cellValue4);

			count_find++;
		}
	}

	MessageBox::Show("Количество найденных заказов = " + count_find, "Ошибка");

	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::textBox_search_product_Text(System::Object^ sender, System::EventArgs^ e)
{
	productText = textBox_search_product->Text;
	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::textBox_search_stock_Text(System::Object^ sender, System::EventArgs^ e)
{
	stockText = textBox_search_stock->Text;
	return System::Void();
}
//---------------------------------------------------------------------------------------------------------------------------------------------
System::Void iz::MyForm::reboot4_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView3->Rows->Clear();

	return System::Void();
}


