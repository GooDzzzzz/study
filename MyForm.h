#pragma once

namespace iz {

	using namespace System;                                          // подключение простраств имен
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form    // создание класса
	{
	public:
		MyForm(void)						   		            	 //конструктор
		{
			InitializeComponent();
		}

	protected:
		~MyForm()                                                    // деструктор
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button_update;
	private: System::Windows::Forms::Button^ button_delete;
	private: System::Windows::Forms::Button^ button_add;
	private: System::Windows::Forms::Button^ button_download;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button_update2;
	private: System::Windows::Forms::Button^ button_delete2;
	private: System::Windows::Forms::Button^ button_add2;
	private: System::Windows::Forms::Button^ button_download2;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::TextBox^ textBox_search_product;
	private: System::Windows::Forms::TextBox^ textBox_search_stock;
	private: System::Windows::Forms::Button^ button_search;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridView3;
	private: System::Windows::Forms::Button^ reboot1;
	private: System::Windows::Forms::Button^ reboot2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::DataGridView^ dataGridView4;
	private: System::Windows::Forms::Button^ reboot4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ price1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ adress2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ volume2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id3_1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id3_2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ count;
	private: System::Windows::Forms::Button^ reboot3;
	private: System::Windows::Forms::Button^ update3;
	private: System::Windows::Forms::Button^ download3;
	private: System::Windows::Forms::Button^ delete3;
	private: System::Windows::Forms::Button^ add3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn7;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->price1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->reboot1 = (gcnew System::Windows::Forms::Button());
			this->button_update = (gcnew System::Windows::Forms::Button());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->button_download = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->reboot2 = (gcnew System::Windows::Forms::Button());
			this->button_update2 = (gcnew System::Windows::Forms::Button());
			this->button_delete2 = (gcnew System::Windows::Forms::Button());
			this->button_add2 = (gcnew System::Windows::Forms::Button());
			this->button_download2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->id2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->adress2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->volume2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox_search_product = (gcnew System::Windows::Forms::TextBox());
			this->textBox_search_stock = (gcnew System::Windows::Forms::TextBox());
			this->button_search = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->reboot3 = (gcnew System::Windows::Forms::Button());
			this->update3 = (gcnew System::Windows::Forms::Button());
			this->download3 = (gcnew System::Windows::Forms::Button());
			this->delete3 = (gcnew System::Windows::Forms::Button());
			this->add3 = (gcnew System::Windows::Forms::Button());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->id3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->id3_1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->id3_2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->count = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->reboot4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->id1, this->name1,
					this->price1
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(450, 200);
			this->dataGridView1->TabIndex = 0;
			// 
			// id1
			// 
			this->id1->HeaderText = L"ID";
			this->id1->Name = L"id1";
			// 
			// name1
			// 
			this->name1->HeaderText = L"Наименование";
			this->name1->Name = L"name1";
			// 
			// price1
			// 
			this->price1->HeaderText = L"Цена";
			this->price1->Name = L"price1";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->reboot1);
			this->groupBox1->Controls->Add(this->button_update);
			this->groupBox1->Controls->Add(this->button_delete);
			this->groupBox1->Controls->Add(this->button_add);
			this->groupBox1->Controls->Add(this->button_download);
			this->groupBox1->Location = System::Drawing::Point(468, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(266, 200);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Действия с данными о товарах";
			// 
			// reboot1
			// 
			this->reboot1->Location = System::Drawing::Point(82, 148);
			this->reboot1->Name = L"reboot1";
			this->reboot1->Size = System::Drawing::Size(98, 41);
			this->reboot1->TabIndex = 4;
			this->reboot1->Text = L"Очистка таблицы";
			this->reboot1->UseVisualStyleBackColor = true;
			this->reboot1->Click += gcnew System::EventHandler(this, &MyForm::reboot1_Click);
			// 
			// button_update
			// 
			this->button_update->Location = System::Drawing::Point(23, 95);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(98, 39);
			this->button_update->TabIndex = 3;
			this->button_update->Text = L"Обновить";
			this->button_update->UseVisualStyleBackColor = true;
			this->button_update->Click += gcnew System::EventHandler(this, &MyForm::button_update_Click);
			// 
			// button_delete
			// 
			this->button_delete->Location = System::Drawing::Point(144, 95);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(98, 39);
			this->button_delete->TabIndex = 2;
			this->button_delete->Text = L"Удалить";
			this->button_delete->UseVisualStyleBackColor = true;
			this->button_delete->Click += gcnew System::EventHandler(this, &MyForm::button_delete_Click);
			// 
			// button_add
			// 
			this->button_add->Location = System::Drawing::Point(144, 32);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(98, 39);
			this->button_add->TabIndex = 1;
			this->button_add->Text = L"Добавить";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &MyForm::button_add_Click);
			// 
			// button_download
			// 
			this->button_download->Location = System::Drawing::Point(23, 32);
			this->button_download->Name = L"button_download";
			this->button_download->Size = System::Drawing::Size(98, 39);
			this->button_download->TabIndex = 0;
			this->button_download->Text = L"Загрузить";
			this->button_download->UseVisualStyleBackColor = true;
			this->button_download->Click += gcnew System::EventHandler(this, &MyForm::button_download_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->reboot2);
			this->groupBox2->Controls->Add(this->button_update2);
			this->groupBox2->Controls->Add(this->button_delete2);
			this->groupBox2->Controls->Add(this->button_add2);
			this->groupBox2->Controls->Add(this->button_download2);
			this->groupBox2->Location = System::Drawing::Point(468, 229);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(266, 200);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Действия с данными о складах";
			// 
			// reboot2
			// 
			this->reboot2->Location = System::Drawing::Point(82, 145);
			this->reboot2->Name = L"reboot2";
			this->reboot2->Size = System::Drawing::Size(98, 41);
			this->reboot2->TabIndex = 5;
			this->reboot2->Text = L"Очистка таблицы";
			this->reboot2->UseVisualStyleBackColor = true;
			this->reboot2->Click += gcnew System::EventHandler(this, &MyForm::reboot2_Click);
			// 
			// button_update2
			// 
			this->button_update2->Location = System::Drawing::Point(23, 95);
			this->button_update2->Name = L"button_update2";
			this->button_update2->Size = System::Drawing::Size(98, 39);
			this->button_update2->TabIndex = 3;
			this->button_update2->Text = L"Обновить";
			this->button_update2->UseVisualStyleBackColor = true;
			this->button_update2->Click += gcnew System::EventHandler(this, &MyForm::button_update2_Click);
			// 
			// button_delete2
			// 
			this->button_delete2->Location = System::Drawing::Point(144, 95);
			this->button_delete2->Name = L"button_delete2";
			this->button_delete2->Size = System::Drawing::Size(98, 39);
			this->button_delete2->TabIndex = 2;
			this->button_delete2->Text = L"Удалить";
			this->button_delete2->UseVisualStyleBackColor = true;
			this->button_delete2->Click += gcnew System::EventHandler(this, &MyForm::button_delete2_Click);
			// 
			// button_add2
			// 
			this->button_add2->Location = System::Drawing::Point(144, 32);
			this->button_add2->Name = L"button_add2";
			this->button_add2->Size = System::Drawing::Size(98, 39);
			this->button_add2->TabIndex = 1;
			this->button_add2->Text = L"Добавить";
			this->button_add2->UseVisualStyleBackColor = true;
			this->button_add2->Click += gcnew System::EventHandler(this, &MyForm::button_add2_Click);
			// 
			// button_download2
			// 
			this->button_download2->Location = System::Drawing::Point(23, 32);
			this->button_download2->Name = L"button_download2";
			this->button_download2->Size = System::Drawing::Size(98, 39);
			this->button_download2->TabIndex = 0;
			this->button_download2->Text = L"Загрузить";
			this->button_download2->UseVisualStyleBackColor = true;
			this->button_download2->Click += gcnew System::EventHandler(this, &MyForm::button_download2_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->id2, this->adress2,
					this->volume2
			});
			this->dataGridView2->Location = System::Drawing::Point(12, 229);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(450, 200);
			this->dataGridView2->TabIndex = 4;
			// 
			// id2
			// 
			this->id2->HeaderText = L"ID";
			this->id2->Name = L"id2";
			// 
			// adress2
			// 
			this->adress2->HeaderText = L"Адрес";
			this->adress2->Name = L"adress2";
			// 
			// volume2
			// 
			this->volume2->HeaderText = L"Вместимость";
			this->volume2->Name = L"volume2";
			// 
			// textBox_search_product
			// 
			this->textBox_search_product->Location = System::Drawing::Point(468, 685);
			this->textBox_search_product->Name = L"textBox_search_product";
			this->textBox_search_product->Size = System::Drawing::Size(197, 21);
			this->textBox_search_product->TabIndex = 6;
			this->textBox_search_product->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_search_product_Text);
			// 
			// textBox_search_stock
			// 
			this->textBox_search_stock->Location = System::Drawing::Point(468, 725);
			this->textBox_search_stock->Name = L"textBox_search_stock";
			this->textBox_search_stock->Size = System::Drawing::Size(197, 21);
			this->textBox_search_stock->TabIndex = 7;
			this->textBox_search_stock->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_search_stock_Text);
			// 
			// button_search
			// 
			this->button_search->Location = System::Drawing::Point(491, 757);
			this->button_search->Name = L"button_search";
			this->button_search->Size = System::Drawing::Size(98, 39);
			this->button_search->TabIndex = 8;
			this->button_search->Text = L"Поиск";
			this->button_search->UseVisualStyleBackColor = true;
			this->button_search->Click += gcnew System::EventHandler(this, &MyForm::button_search_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(468, 662);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(155, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Введите наименование товара";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(468, 709);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Введите склад";
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->dataGridViewTextBoxColumn5,
					this->dataGridViewTextBoxColumn6, this->dataGridViewTextBoxColumn8, this->dataGridViewTextBoxColumn7
			});
			this->dataGridView3->Location = System::Drawing::Point(12, 662);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->Size = System::Drawing::Size(450, 134);
			this->dataGridView3->TabIndex = 11;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"ID";
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"Наименование";
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			// 
			// dataGridViewTextBoxColumn8
			// 
			this->dataGridViewTextBoxColumn8->HeaderText = L"Склад";
			this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->HeaderText = L"Количество";
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->reboot3);
			this->groupBox3->Controls->Add(this->update3);
			this->groupBox3->Controls->Add(this->download3);
			this->groupBox3->Controls->Add(this->delete3);
			this->groupBox3->Controls->Add(this->add3);
			this->groupBox3->Location = System::Drawing::Point(468, 444);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(266, 200);
			this->groupBox3->TabIndex = 6;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Действия с данными о заказах";
			// 
			// reboot3
			// 
			this->reboot3->Location = System::Drawing::Point(82, 144);
			this->reboot3->Name = L"reboot3";
			this->reboot3->Size = System::Drawing::Size(98, 41);
			this->reboot3->TabIndex = 10;
			this->reboot3->Text = L"Очистка таблицы";
			this->reboot3->UseVisualStyleBackColor = true;
			this->reboot3->Click += gcnew System::EventHandler(this, &MyForm::reboot3_Click);
			// 
			// update3
			// 
			this->update3->Location = System::Drawing::Point(23, 94);
			this->update3->Name = L"update3";
			this->update3->Size = System::Drawing::Size(98, 39);
			this->update3->TabIndex = 9;
			this->update3->Text = L"Обновить";
			this->update3->UseVisualStyleBackColor = true;
			this->update3->Click += gcnew System::EventHandler(this, &MyForm::update3_Click);
			// 
			// download3
			// 
			this->download3->Location = System::Drawing::Point(23, 31);
			this->download3->Name = L"download3";
			this->download3->Size = System::Drawing::Size(98, 39);
			this->download3->TabIndex = 6;
			this->download3->Text = L"Загрузить";
			this->download3->UseVisualStyleBackColor = true;
			this->download3->Click += gcnew System::EventHandler(this, &MyForm::download3_Click);
			// 
			// delete3
			// 
			this->delete3->Location = System::Drawing::Point(144, 94);
			this->delete3->Name = L"delete3";
			this->delete3->Size = System::Drawing::Size(98, 39);
			this->delete3->TabIndex = 8;
			this->delete3->Text = L"Удалить";
			this->delete3->UseVisualStyleBackColor = true;
			this->delete3->Click += gcnew System::EventHandler(this, &MyForm::delete3_Click);
			// 
			// add3
			// 
			this->add3->Location = System::Drawing::Point(144, 31);
			this->add3->Name = L"add3";
			this->add3->Size = System::Drawing::Size(98, 39);
			this->add3->TabIndex = 7;
			this->add3->Text = L"Добавить";
			this->add3->UseVisualStyleBackColor = true;
			this->add3->Click += gcnew System::EventHandler(this, &MyForm::add3_Click);
			// 
			// dataGridView4
			// 
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->id3, this->id3_1,
					this->id3_2, this->count
			});
			this->dataGridView4->Location = System::Drawing::Point(12, 444);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->Size = System::Drawing::Size(450, 200);
			this->dataGridView4->TabIndex = 5;
			// 
			// id3
			// 
			this->id3->HeaderText = L"ID";
			this->id3->Name = L"id3";
			// 
			// id3_1
			// 
			this->id3_1->HeaderText = L"ID продукта";
			this->id3_1->Name = L"id3_1";
			// 
			// id3_2
			// 
			this->id3_2->HeaderText = L"ID Склада";
			this->id3_2->Name = L"id3_2";
			// 
			// count
			// 
			this->count->HeaderText = L"Количество";
			this->count->Name = L"count";
			// 
			// reboot4
			// 
			this->reboot4->Location = System::Drawing::Point(612, 757);
			this->reboot4->Name = L"reboot4";
			this->reboot4->Size = System::Drawing::Size(98, 41);
			this->reboot4->TabIndex = 5;
			this->reboot4->Text = L"Очистка таблицы";
			this->reboot4->UseVisualStyleBackColor = true;
			this->reboot4->Click += gcnew System::EventHandler(this, &MyForm::reboot4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Menu;
			this->ClientSize = System::Drawing::Size(743, 805);
			this->Controls->Add(this->reboot4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->dataGridView4);
			this->Controls->Add(this->dataGridView3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_search);
			this->Controls->Add(this->textBox_search_stock);
			this->Controls->Add(this->textBox_search_product);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Оптовая поставка фруктов";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button_download_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_update_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_delete_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void reboot1_Click(System::Object^ sender, System::EventArgs^ e);
		   //---------------------------------------------------------------------------------------------------------------
	private: System::Void button_download2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_add2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_update2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_delete2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void reboot2_Click(System::Object^ sender, System::EventArgs^ e);
		   //---------------------------------------------------------------------------------------------------------------
	private: System::Void download3_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void add3_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void update3_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void delete3_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void reboot3_Click(System::Object^ sender, System::EventArgs^ e);
		   //---------------------------------------------------------------------------------------------------------------
	private: System::Void button_search_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox_search_product_Text(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox_search_stock_Text(System::Object^ sender, System::EventArgs^ e);
	private: System::Void reboot4_Click(System::Object^ sender, System::EventArgs^ e);
		   //---------------------------------------------------------------------------------------------------------------
	private:
		System::String^ productText = "";
		System::String^ stockText = "";
	};
}
