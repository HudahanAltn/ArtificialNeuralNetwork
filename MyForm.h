#pragma once

#include <Windows.h>
#include <iostream>
#include <time.h>
#include "Resource.h"
#include "Process.h"
#include "Learning.h"
#include "Normalization.h"
namespace ArtificialNeuralNetwork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm i�in �zet
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Olu�turucu kodunu buraya ekle
			//
			label3->Text = "";
			label4->Text = "";
			label5->Text = "";
			label6->Text = "";
			label7->Text = "";
			pen = gcnew Pen(Color::Red, 3.0f);
			instanceValue = classValue = totalInstanceSize = constTotalInstanceSize = classId = 0;
			
			
		}

		Int32 instanceValue;//her s�n�fa ait �rnek say�s�
	public:
		Pen^ pen;//s�n�ftaki �rneklerin picturebox'ta g�r�nmesini sa�layacak olan kalem nesnesi.
	private: System::Windows::Forms::Label^ label10;
	public:
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	public:
		Int32 classValue;//s�n�f say�s�
		Instance* instances;// ekrana t�klanan noktalar� tutacak yani �rneklerin dizisi.
		int totalInstanceSize, constTotalInstanceSize;//toplam �rnek say�s� classValue*instanceValue.
		int classId;//her s�n�f�n e��iz �d'si olmal�d�r.
		double* weight;
	
	protected:
		/// <summary>
		///Kullan�lan t�m kaynaklar� temizleyin.
		/// </summary>
		~MyForm(){
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �nitializationToolStripMenuItem;
	private: System::Windows::Forms::TreeView^ treeView1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ToolStripMenuItem^ randomizeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ trainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ perceptronToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deltaToolStripMenuItem;
	private:System::ComponentModel::Container ^components;






#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasar�mc� deste�i i�in gerekli metot - bu metodun 
		///i�eri�ini kod d�zenleyici ile de�i�tirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�nitializationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->randomizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->perceptronToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deltaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->Location = System::Drawing::Point(15, 50);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(500, 500);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->processToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1303, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->�nitializationToolStripMenuItem });
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(72, 24);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// �nitializationToolStripMenuItem
			// 
			this->�nitializationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->randomizeToolStripMenuItem,
					this->exitToolStripMenuItem, this->trainingToolStripMenuItem
			});
			this->�nitializationToolStripMenuItem->Name = L"�nitializationToolStripMenuItem";
			this->�nitializationToolStripMenuItem->Size = System::Drawing::Size(174, 26);
			this->�nitializationToolStripMenuItem->Text = L"Initialization";
			// 
			// randomizeToolStripMenuItem
			// 
			this->randomizeToolStripMenuItem->Name = L"randomizeToolStripMenuItem";
			this->randomizeToolStripMenuItem->Size = System::Drawing::Size(167, 26);
			this->randomizeToolStripMenuItem->Text = L"Randomize";
			this->randomizeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::randomizeToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(167, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// trainingToolStripMenuItem
			// 
			this->trainingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->perceptronToolStripMenuItem,
					this->deltaToolStripMenuItem
			});
			this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			this->trainingToolStripMenuItem->Size = System::Drawing::Size(167, 26);
			this->trainingToolStripMenuItem->Text = L"Training";
			// 
			// perceptronToolStripMenuItem
			// 
			this->perceptronToolStripMenuItem->Name = L"perceptronToolStripMenuItem";
			this->perceptronToolStripMenuItem->Size = System::Drawing::Size(163, 26);
			this->perceptronToolStripMenuItem->Text = L"Perceptron";
			this->perceptronToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::perceptronToolStripMenuItem_Click);
			// 
			// deltaToolStripMenuItem
			// 
			this->deltaToolStripMenuItem->Name = L"deltaToolStripMenuItem";
			this->deltaToolStripMenuItem->Size = System::Drawing::Size(163, 26);
			this->deltaToolStripMenuItem->Text = L"Delta";
			this->deltaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deltaToolStripMenuItem_Click);
			// 
			// treeView1
			// 
			this->treeView1->LineColor = System::Drawing::Color::Empty;
			this->treeView1->Location = System::Drawing::Point(0, 0);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(121, 97);
			this->treeView1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::PaleGoldenrod;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label1->Location = System::Drawing::Point(743, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(154, 22);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Class Number    ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::PaleGoldenrod;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->Location = System::Drawing::Point(743, 93);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(153, 22);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Instance Number";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(934, 50);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 22);
			this->numericUpDown1->TabIndex = 4;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(934, 92);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 22);
			this->numericUpDown2->TabIndex = 5;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Khaki;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->button1->Location = System::Drawing::Point(743, 136);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(311, 36);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Se�imi Onayla";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Khaki;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->button2->Location = System::Drawing::Point(744, 178);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(310, 36);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Tekrar Se�im Yap";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(741, 248);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"x1 = 0    x2 = 0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(743, 279);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(287, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Eklenebilir �rnek adedi: 0  Class Id: Unkown ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(1125, 50);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(46, 17);
			this->label5->TabIndex = 10;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(1125, 77);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 17);
			this->label6->TabIndex = 11;
			this->label6->Text = L"label6";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(1125, 98);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(46, 17);
			this->label7->TabIndex = 12;
			this->label7->Text = L"label7";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(744, 317);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(143, 17);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Total Cycle Count = 0";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(747, 350);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(64, 17);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Error = 0";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(747, 410);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(217, 181);
			this->textBox1->TabIndex = 15;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(1021, 410);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(215, 181);
			this->textBox2->TabIndex = 16;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(744, 386);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(63, 17);
			this->label10->TabIndex = 17;
			this->label10->Text = L"�rnekler";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(1021, 386);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(130, 17);
			this->label11->TabIndex = 18;
			this->label11->Text = L"Normalize �rnekler";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FloralWhite;
			this->ClientSize = System::Drawing::Size(1303, 603);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		//picture box eksen do�rular� �izen fonksiyon
		Pen^ pen = gcnew Pen(Color::Gray, 2.5f);
		int center_width, center_height;
		center_width = (int)(pictureBox1->Width / 2);
		center_height = (int)(pictureBox1->Height / 2);
		e->Graphics->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);
		e->Graphics->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);
	}
	
    private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	    /*picturebox �zerine mouse ile t�klan�nca tetiklenen fonksiyon.Burada kullan�c� ekrana t�klay�nca picturebox'ta hem noktalar�
		g�sterip hemde konum de�erlerini alaca��z.*/
		
		if (classValue > 0 ){
			if (instanceValue > 0) {
				
				int temp_x, temp_y;
				double x1, x2; //x1 = width, x2 = height
				//mouse ile t�klay�nca ekran�n konum de�erleri temp_x ve temp_y de�i�kenlerine atan�r.
				temp_x = (Convert::ToInt32(e->X));
				temp_y = (Convert::ToInt32(e->Y));

				// Noktalarin ana eksenin merkezine gore tasinmasi.x1 yatay eksen, x2 dikey eksen.
				x1 = (double)(temp_x - (pictureBox1->Width >> 1));
				x2 = (double)((pictureBox1->Height >> 1) - temp_y);

				//her t�klamada �rnekler diziye ge�irilir.
				instances[constTotalInstanceSize - totalInstanceSize].id = classId;
				instances[constTotalInstanceSize - totalInstanceSize].x1 = x1;
				instances[constTotalInstanceSize - totalInstanceSize].x2 = x2;

				/*MessageBox::Show("Class degeri:" + classValue.ToString() + "  instance de�eri:" + instanceValue.ToString());*/
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);

				label3->Text = "x1 = " + Convert::ToString(instances[constTotalInstanceSize - totalInstanceSize].x1) + "    x2 = " + Convert::ToString(instances[constTotalInstanceSize - totalInstanceSize].x2);
				label4->Text = "Eklenebilir �rnek adedi: " + Convert::ToString(totalInstanceSize - 1) + " Class Id: " + Convert::ToString(classId);
				textBox1->Text += "Id: " + Convert::ToString(classId) + "   x1 = " + Convert::ToString(instances[constTotalInstanceSize - totalInstanceSize].x1) + "    x2 = " + Convert::ToString(instances[constTotalInstanceSize - totalInstanceSize].x2 + "\r\n");
				instanceValue--;
				totalInstanceSize--;
			}
			else {
				classValue--;
				classId = classId + 2;
				instanceValue = Decimal::ToInt32(numericUpDown2->Value);
				System::Random^ rastgele = gcnew System::Random();
				pen = gcnew Pen(System::Drawing::Color::FromArgb(rastgele->Next(256), rastgele->Next(256), rastgele->Next(256)), 3.0f);

			}

		}
		else {
			MessageBox::Show("T�m S�n�f ve �rnekler eklenmi�tir.");
		}

    }

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//kullan�c� girilecek s�n�f say�s� ve her s�n�fa ait �rnek say�s�n� se�er ve onayla butonuna t�klar.

		//s�n�f say�s� ve her s�n�fa ait �rnek say�s� al�n�r.
		classValue = Decimal::ToInt32(numericUpDown1->Value);
		instanceValue = Decimal::ToInt32(numericUpDown2->Value);

		//t�klama boyunca bu say�lar�n de�i�mesini engellemek i�in nesneler devre d��� b�rak�l�r.
		numericUpDown1->Enabled = false;
		numericUpDown2->Enabled = false;

		totalInstanceSize = classValue * instanceValue;//toplam �rnek say�s�
		constTotalInstanceSize = classValue * instanceValue;//toplam �rnek say�s� ama bu sabit kalacak

		classId = -1;//s�n�f id'si 1 den ba�layacak
		instances = new Instance[totalInstanceSize];//bellekte toplam �rnek say�s� kadar alan ayr�lacak.
		
		label3->Text = "x1 = 0  "  + "  x2 = 0" ;
		label4->Text = "Eklenebilir �rnek adedi: 0 " + " Class Id: Unkown" ;

		MessageBox::Show("PictureBox �zerindeki koordinat alanlar�na �rnekleri t�klayarak yerle�tiriniz.");


	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	
		delete[] instances;
		pictureBox1->Refresh();
		classValue = 0;
		instanceValue = 0;
		totalInstanceSize = 0;
		constTotalInstanceSize = 0;
		classId = 0;
		numericUpDown1->Enabled = true;
		numericUpDown2->Enabled = true;

		label3->Text = "x1 = 0  " + "  x2 = 0";
		label4->Text = "Eklenebilir �rnek adedi: 0 " + " Class Id: Unkown";
		label5->Text = "w[0]: 0 " ;
		label6->Text = "w[1]: 0 " ;
		label7->Text = "w[2]: 0 " ;
		
	}

	private: System::Void randomizeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		//rastgele do�ru �izimi

		Pen^ pen = gcnew Pen(Color::Green, 3.0f);

		int min_x, max_x, min_y, max_y;
		
		int Dim = 2;
		weight = new double[Dim + 1];
		srand(time(0));
		for (int i = 0; i < 3; i++) {
		weight[i] = ((double)rand() / (RAND_MAX));
		}

		label5->Text = "w[0]: " + System::Convert::ToString(weight[0]);
		label6->Text = "w[1]: " + System::Convert::ToString(weight[1]);
		label7->Text = "w[2]: " + System::Convert::ToString(weight[2]);

		min_x = (this->pictureBox1->Width) / -2;
		min_y = YPoint(min_x, weight);
		max_x = (this->pictureBox1->Width) / 2;
		max_y = YPoint(max_x, weight);
		pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);

	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		//exit form
		exit(-1);
	}


	private: System::Void perceptronToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		//perceptron learning

		//double totalError = 0.0;

		//int totalCycleCount = 0;

		//double tolerance = 1e-9; // Tolerans de�eri

		//while (true) {
		//	for (int i = 0; i < constTotalInstanceSize; i++) {

		//		totalError += perceptronLearning(instances[i], weight, 0.1);


		//	}
		//	totalCycleCount++;

		//	if (std::abs(totalError - 0) < tolerance) {
		//		break;
		//	}
		//	else {
		//		totalError = 0.0;
		//	}
		//}

		//label8->Text = "Total Cycle Count = " + System::Convert::ToString(totalCycleCount);
		//
		//Pen^ pen = gcnew Pen(Color::Purple, 3.0f);

		//int min_x, max_x, min_y, max_y;

		//label5->Text = "w[0]: " + System::Convert::ToString(weight[0]);
		//label6->Text = "w[1]: " + System::Convert::ToString(weight[1]);
		//label7->Text = "w[2]: " + System::Convert::ToString(weight[2]);

		//min_x = (this->pictureBox1->Width) / -2;
		//min_y = YPoint(min_x, weight);
		//max_x = (this->pictureBox1->Width) / 2;
		//max_y = YPoint(max_x, weight);
		//pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);
		//


		Pen^ pen = gcnew Pen(Color::Purple, 3.0f);

		int min_x, max_x, min_y, max_y;

		long int cycle = 10000000;
		bool allCyclesDone;
		int totalCycleCount = 0;
		for (int i = 0; i < cycle; i++) {
			totalCycleCount++;
			bool* trainingIsDone = new bool[constTotalInstanceSize];

			allCyclesDone = true; //Butun cycle'lar tamamlandimi

			for (int j = 0; j < constTotalInstanceSize; j++) {
				trainingIsDone[j] = perceptronLearning(instances[j], weight, 0.1);
			}
				
			for (int k = 0; k < constTotalInstanceSize; k++)
				if (trainingIsDone[k] == 0)
					allCyclesDone = false;

			if (allCyclesDone) {
				delete[] trainingIsDone;
				break;
			}
				
		}

		label5->Text = "w[0]: " + System::Convert::ToString(weight[0]);
		label6->Text = "w[1]: " + System::Convert::ToString(weight[1]);
		label7->Text = "w[2]: " + System::Convert::ToString(weight[2]);
		label8->Text = "Total Cycle Count = " + System::Convert::ToString(totalCycleCount);

		min_x = (this->pictureBox1->Width) / -2;
		min_y = YPoint(min_x, weight);
		max_x = (this->pictureBox1->Width) / 2;
		max_y = YPoint(max_x, weight);

		pen->Color = Color::Purple;
		pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);

		
	}
	private: System::Void deltaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		//delta learning

		Pen^ pen = gcnew Pen(Color::Purple, 3.0f);

		/*for (int i = 0; i < constTotalInstanceSize; i++) {

			instances[i] = Normalization(instances[i]);
		}*/
	

		double totalX = 0.0;
		double totalY = 0.0;

		for (int i = 0; i < constTotalInstanceSize; i++) {
			totalX += instances[i].x1;
			totalY += instances[i].x2;
		}

		double mean_X = totalX / constTotalInstanceSize;
		double mean_Y = totalY / constTotalInstanceSize;

		
		double totalX2 = 0.0;
		double totalY2 = 0.0;
		for (int i = 0; i < constTotalInstanceSize; i++) {
			totalX2 += pow(instances[i].x1 - mean_X, 2);
			totalY2 += pow(instances[i].x2 - mean_Y, 2);
		}

		double standartDev_X = sqrt(totalX2 / (constTotalInstanceSize-1));
		double standartDev_Y = sqrt(totalY2 / (constTotalInstanceSize - 1));

		for (int i = 0; i < constTotalInstanceSize; i++) {

			instances[i] = batchNormalization(instances[i],mean_X,standartDev_X,mean_Y,standartDev_Y);
			textBox2->Text += "Id: " + Convert::ToString(instances[i].id) + "   x1 = " + Convert::ToString(instances[i].x1) + "    x2 = " + Convert::ToString(instances[i].x2 + "\r\n");
		}



	

		int min_x, max_x, min_y, max_y;

		long int maxCycle = 100000;
	
		int totalCycleCount = 0;

		double error = 0.0;


		while (true) {

			error = 0.0;
			for (int i= 0; i < constTotalInstanceSize; i++) {
				error += deltaLearning(instances[i], weight, 0.1);
			}
			totalCycleCount++;

			double err = (error / constTotalInstanceSize);
			
			
			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);
			pictureBox1->Refresh();
			if (err < 0.1 || totalCycleCount == maxCycle) {
				break;
			}
		}



		for (int i = 0; i < constTotalInstanceSize; i++) {

			int x = instances[i].x1*30 + (pictureBox1->Width >> 1);
			int y = (pictureBox1->Height >> 1) - instances[i].x2*30;
			
			pictureBox1->CreateGraphics()->DrawLine(pen, x - 5, y, x + 5, y);
			pictureBox1->CreateGraphics()->DrawLine(pen, x, y - 5, x, y + 5);
		}
	
		label5->Text = "w[0]: " + System::Convert::ToString(weight[0]);
		label6->Text = "w[1]: " + System::Convert::ToString(weight[1]);
		label7->Text = "w[2]: " + System::Convert::ToString(weight[2]);
		label8->Text = "Total Cycle Count = " + System::Convert::ToString(totalCycleCount);
		label9->Text = "Error = " + System::Convert::ToString(error/constTotalInstanceSize);


		min_x = (this->pictureBox1->Width) / -2;
		min_y = YPoint(min_x, weight);
		max_x = (this->pictureBox1->Width) / 2;
		max_y = YPoint(max_x, weight);

		pen->Color = Color::Yellow;
		pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);

	}

};
}

