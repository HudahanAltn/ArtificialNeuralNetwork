#pragma once

#include <Windows.h>
#include <iostream>
#include <time.h>
#include "Resource.h"
#include "Process.h"

namespace ArtificialNeuralNetwork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm için özet
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
			label3->Text = "";
			label4->Text = "";
			label5->Text = "";
			label6->Text = "";
			label7->Text = "";
			pen = gcnew Pen(Color::Black, 3.0f);
			instanceValue = classValue = totalInstanceSize = constTotalInstanceSize = classId = 0;
			
		}

		Int32 instanceValue;//her sýnýfa ait örnek sayýsý
		Pen^ pen;//sýnýftaki örneklerin picturebox'ta görünmesini saðlayacak olan kalem nesnesi.
		Int32 classValue;//sýnýf sayýsý
		Instance* instances;// ekrana týklanan noktalarý tutacak yani örneklerin dizisi.
		int totalInstanceSize, constTotalInstanceSize;//toplam örnek sayýsý classValue*instanceValue.
		int classId;//her sýnýfýn eþþiz ýd'si olmalýdýr.
		double* weight;
	
	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
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
	private: System::Windows::Forms::ToolStripMenuItem^ ýnitializationToolStripMenuItem;
	private: System::Windows::Forms::TreeView^ treeView1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ToolStripMenuItem^ randomizeToolStripMenuItem;
	private:
		/// <summary>
		///Gerekli tasarýmcý deðiþkeni.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarýmcý desteði için gerekli metot - bu metodun 
		///içeriðini kod düzenleyici ile deðiþtirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ýnitializationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->randomizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ýnitializationToolStripMenuItem });
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(72, 24);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// ýnitializationToolStripMenuItem
			// 
			this->ýnitializationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->randomizeToolStripMenuItem });
			this->ýnitializationToolStripMenuItem->Name = L"ýnitializationToolStripMenuItem";
			this->ýnitializationToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->ýnitializationToolStripMenuItem->Text = L"Initialization";
			// 
			// randomizeToolStripMenuItem
			// 
			this->randomizeToolStripMenuItem->Name = L"randomizeToolStripMenuItem";
			this->randomizeToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->randomizeToolStripMenuItem->Text = L"Randomize";
			this->randomizeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::randomizeToolStripMenuItem_Click);
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
			this->label1->Location = System::Drawing::Point(608, 50);
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
			this->label2->Location = System::Drawing::Point(608, 93);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(153, 22);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Instance Number";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(799, 50);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 22);
			this->numericUpDown1->TabIndex = 4;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(799, 92);
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
			this->button1->Location = System::Drawing::Point(608, 136);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(311, 36);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Seçimi Onayla";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Khaki;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->button2->Location = System::Drawing::Point(609, 178);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(310, 36);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Tekrar Seçim Yap";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(606, 248);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"x1 = 0    x2 = 0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(608, 279);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(287, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Eklenebilir örnek adedi: 0  Class Id: Unkown ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(990, 50);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(46, 17);
			this->label5->TabIndex = 10;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(990, 77);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 17);
			this->label6->TabIndex = 11;
			this->label6->Text = L"label6";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(990, 98);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(46, 17);
			this->label7->TabIndex = 12;
			this->label7->Text = L"label7";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FloralWhite;
			this->ClientSize = System::Drawing::Size(1303, 603);
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

		//picture box eksen doðrularý çizen fonksiyon
		Pen^ pen = gcnew Pen(Color::Gray, 2.5f);
		int center_width, center_height;
		center_width = (int)(pictureBox1->Width / 2);
		center_height = (int)(pictureBox1->Height / 2);
		e->Graphics->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);
		e->Graphics->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);
	}
	
    private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	    /*picturebox üzerine mouse ile týklanýnca tetiklenen fonksiyon.Burada kullanýcý ekrana týklayýnca picturebox'ta hem noktalarý
		gösterip hemde konum deðerlerini alacaðýz.*/
		
		if (classValue > 0 ){
			if (instanceValue > 0) {
				
				int temp_x, temp_y;
				double x1, x2; //x1 = width, x2 = height
				//mouse ile týklayýnca ekranýn konum deðerleri temp_x ve temp_y deðiþkenlerine atanýr.
				temp_x = (Convert::ToInt32(e->X));
				temp_y = (Convert::ToInt32(e->Y));

				// Noktalarin ana eksenin merkezine gore tasinmasi.x1 yatay eksen, x2 dikey eksen.
				x1 = (double)(temp_x - (pictureBox1->Width >> 1));
				x2 = (double)((pictureBox1->Height >> 1) - temp_y);

				//her týklamada örnekler diziye geçirilir.
				instances[constTotalInstanceSize - totalInstanceSize].id = classId;
				instances[constTotalInstanceSize - totalInstanceSize].x1 = x1;
				instances[constTotalInstanceSize - totalInstanceSize].x2 = x2;

				/*MessageBox::Show("Class degeri:" + classValue.ToString() + "  instance deðeri:" + instanceValue.ToString());*/
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);

				label3->Text = "x1 = " + Convert::ToString(instances[constTotalInstanceSize - totalInstanceSize].x1) + "    x2 = " + Convert::ToString(instances[constTotalInstanceSize - totalInstanceSize].x2);
				label4->Text = "Eklenebilir örnek adedi: " + Convert::ToString(totalInstanceSize - 1) + " Class Id: " + Convert::ToString(classId);
				instanceValue--;
				totalInstanceSize--;
			}
			else {
				classValue--;
				classId++;
				instanceValue = Decimal::ToInt32(numericUpDown2->Value);
				System::Random^ rastgele = gcnew System::Random();
				pen = gcnew Pen(System::Drawing::Color::FromArgb(rastgele->Next(256), rastgele->Next(256), rastgele->Next(256)), 3.0f);

			}

		}
		else {
			MessageBox::Show("Tüm Sýnýf ve Örnekler eklenmiþtir.");
		}

    }

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//kullanýcý girilecek sýnýf sayýsý ve her sýnýfa ait örnek sayýsýný seçer ve onayla butonuna týklar.

		//sýnýf sayýsý ve her sýnýfa ait örnek sayýsý alýnýr.
		classValue = Decimal::ToInt32(numericUpDown1->Value);
		instanceValue = Decimal::ToInt32(numericUpDown2->Value);

		//týklama boyunca bu sayýlarýn deðiþmesini engellemek için nesneler devre dýþý býrakýlýr.
		numericUpDown1->Enabled = false;
		numericUpDown2->Enabled = false;

		totalInstanceSize = classValue * instanceValue;//toplam örnek sayýsý
		constTotalInstanceSize = classValue * instanceValue;//toplam örnek sayýsý ama bu sabit kalacak

		classId = 1;//sýnýf id'si 1 den baþlayacak
		instances = new Instance[totalInstanceSize];//bellekte toplam örnek sayýsý kadar alan ayrýlacak.
		
		label3->Text = "x1 = 0  "  + "  x2 = 0" ;
		label4->Text = "Eklenebilir örnek adedi: 0 " + " Class Id: Unkown" ;

		MessageBox::Show("PictureBox üzerindeki koordinat alanlarýna örnekleri týklayarak yerleþtiriniz.");


	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		
	/*	numericUpDown1->Enabled = true;
		numericUpDown2->Enabled = true;

		classValue = 2;
		instanceValue = 2;

		pen = gcnew Pen(Color::Black, 3.0f);
		instanceValue = classValue = totalInstanceSize = constTotalInstanceSize = classId = 0;
		delete* instances*/

		MessageBox::Show("class" + instances[0].id + "  x1:" + instances[0].x1 + " x2:" + instances[0].x2 + "\n" +
			"class" + instances[1].id + "  x1:" + instances[1].x1 + " x2:" + instances[1].x2 + "\n" +
			"class" + instances[2].id + "  x1:" + instances[2].x1 + " x2:" + instances[2].x2 + "\n" +
			"class" + instances[3].id + "  x1:" + instances[3].x1 + " x2:" + instances[3].x2 + "\n" +
			"class" + instances[4].id + "  x1:" + instances[4].x1 + " x2:" + instances[4].x2 + "\n");
		
	
		
	}
	private: System::Void randomizeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		//rastgele doðru çizimi

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
};
}
