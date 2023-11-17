#pragma once

#include <Windows.h>
#include <vector>
#include <iostream>
#include <time.h>
#include "Resource.h"
#include "Process.h"
#include "Learning.h"
#include "Normalization.h"
#include "Utilities.h"

namespace ArtificialNeuralNetwork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
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
			 numericUpDown1->Enabled = true;//ilk baþlarken sýnýf sayýsý seçilsin
			 numericUpDown2->Enabled = false;
			 button1->Enabled = false;
			 button2->Enabled = false;
			 button3->Enabled = true;
			//
			label3->Text = "";
			label4->Text = "";
			label5->Text = "";
			label6->Text = "";
			label7->Text = "";

			pen = gcnew Pen(Color::Red, 3.0f);//örnek ilk baþta kýrmýzý renli olacak
			classValue = classTag =  totalInstanceSize = constTotalInstanceSize = classId = choosenError = choosenCycle = 0;
			instances2 = gcnew List<Instance>();
			colors = gcnew List<Color>();
		}

	public:
		Pen^ pen;//sýnýftaki örneklerin picturebox'ta görünmesini saðlayacak olan kalem nesnesi.
		Int32 classValue;//sýnýf sayýsý
		Int32 classTag;//sýnýfýn etiketi(1,2,3,4,5,6,7,8,9,10)
		List<Instance>^ instances2;// ekrana týklanan noktalarý tutacak yani örneklerin listesi.
		List<Color>^ colors;
		int totalInstanceSize, constTotalInstanceSize;//toplam örnek sayýsý 
		int classId;//her sýnýfýn eþþiz ýd'si olmalýdýr.
		double* weight;
		double choosenError;
		int choosenCycle;

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
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ToolStripMenuItem^ randomizeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ trainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ perceptronToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deltaToolStripMenuItem;
	private: System::ComponentModel::Container ^components;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::ToolStripMenuItem^ multiCatSLDeltaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ randomizeForMultiCatToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label15;

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
			this->randomizeForMultiCatToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->perceptronToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deltaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->multiCatSLDeltaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
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
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ýnitializationToolStripMenuItem });
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(72, 24);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// ýnitializationToolStripMenuItem
			// 
			this->ýnitializationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->randomizeToolStripMenuItem,
					this->randomizeForMultiCatToolStripMenuItem, this->exitToolStripMenuItem, this->trainingToolStripMenuItem
			});
			this->ýnitializationToolStripMenuItem->Name = L"ýnitializationToolStripMenuItem";
			this->ýnitializationToolStripMenuItem->Size = System::Drawing::Size(174, 26);
			this->ýnitializationToolStripMenuItem->Text = L"Initialization";
			// 
			// randomizeToolStripMenuItem
			// 
			this->randomizeToolStripMenuItem->Name = L"randomizeToolStripMenuItem";
			this->randomizeToolStripMenuItem->Size = System::Drawing::Size(252, 26);
			this->randomizeToolStripMenuItem->Text = L"Randomize";
			this->randomizeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::randomizeToolStripMenuItem_Click);
			// 
			// randomizeForMultiCatToolStripMenuItem
			// 
			this->randomizeForMultiCatToolStripMenuItem->Name = L"randomizeForMultiCatToolStripMenuItem";
			this->randomizeForMultiCatToolStripMenuItem->Size = System::Drawing::Size(252, 26);
			this->randomizeForMultiCatToolStripMenuItem->Text = L"Randomize For MultiCat";
			this->randomizeForMultiCatToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::randomizeForMultiCatToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(252, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// trainingToolStripMenuItem
			// 
			this->trainingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->perceptronToolStripMenuItem,
					this->deltaToolStripMenuItem, this->multiCatSLDeltaToolStripMenuItem
			});
			this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			this->trainingToolStripMenuItem->Size = System::Drawing::Size(252, 26);
			this->trainingToolStripMenuItem->Text = L"Training";
			// 
			// perceptronToolStripMenuItem
			// 
			this->perceptronToolStripMenuItem->Name = L"perceptronToolStripMenuItem";
			this->perceptronToolStripMenuItem->Size = System::Drawing::Size(207, 26);
			this->perceptronToolStripMenuItem->Text = L"Perceptron";
			this->perceptronToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::perceptronToolStripMenuItem_Click);
			// 
			// deltaToolStripMenuItem
			// 
			this->deltaToolStripMenuItem->Name = L"deltaToolStripMenuItem";
			this->deltaToolStripMenuItem->Size = System::Drawing::Size(207, 26);
			this->deltaToolStripMenuItem->Text = L"Delta";
			this->deltaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deltaToolStripMenuItem_Click);
			// 
			// multiCatSLDeltaToolStripMenuItem
			// 
			this->multiCatSLDeltaToolStripMenuItem->Name = L"multiCatSLDeltaToolStripMenuItem";
			this->multiCatSLDeltaToolStripMenuItem->Size = System::Drawing::Size(207, 26);
			this->multiCatSLDeltaToolStripMenuItem->Text = L"MultiCat SL Delta";
			this->multiCatSLDeltaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::multiCatSLDeltaToolStripMenuItem_Click);
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
			this->label1->Size = System::Drawing::Size(130, 22);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Sýnýf Sayýsý    ";
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::PaleGoldenrod;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->Location = System::Drawing::Point(743, 93);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(130, 22);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Sýnýf Etiketi";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(910, 50);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 22);
			this->numericUpDown1->TabIndex = 26;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(910, 93);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 22);
			this->numericUpDown2->TabIndex = 25;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown2_ValueChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Khaki;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->button1->Location = System::Drawing::Point(743, 181);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(253, 36);
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
			this->button2->Location = System::Drawing::Point(1021, 181);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(253, 36);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Tekrar Seçim Yap";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(954, 261);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"x1 = 0    x2 = 0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(740, 294);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(278, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Eklenen Örnek Sayýsý: 0  Class Id: Unkown ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(567, 179);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(45, 17);
			this->label5->TabIndex = 10;
			this->label5->Text = L"w[0] : ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(567, 212);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 17);
			this->label6->TabIndex = 11;
			this->label6->Text = L"w[1] :";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(567, 243);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(41, 17);
			this->label7->TabIndex = 12;
			this->label7->Text = L"w[2] :";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(744, 325);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(143, 17);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Total Cycle Count = 0";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(744, 353);
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
			this->textBox2->Location = System::Drawing::Point(1059, 410);
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
			this->label10->Text = L"Örnekler";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(1056, 386);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(130, 17);
			this->label11->TabIndex = 18;
			this->label11->Text = L"Normalize Örnekler";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(741, 261);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(198, 17);
			this->label12->TabIndex = 19;
			this->label12->Text = L"Eklenen Örnek Konum Bilgisi :";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Khaki;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->button3->Location = System::Drawing::Point(743, 131);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(531, 44);
			this->button3->TabIndex = 20;
			this->button3->Text = L"Neural Aðý Hazýrla";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"10000", L"100000", L"500000", L"1000000", L"2000000",
					L"10000000"
			});
			this->comboBox1->Location = System::Drawing::Point(1136, 48);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->Text = L"10000";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(5) { 0.1, 0.01, 0.001, 0.0001, 1E-05 });
			this->comboBox2->Location = System::Drawing::Point(1136, 91);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 24);
			this->comboBox2->TabIndex = 0;
			
			// 
			// label13
			// 
			this->label13->BackColor = System::Drawing::Color::YellowGreen;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label13->Location = System::Drawing::Point(1070, 48);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(60, 24);
			this->label13->TabIndex = 23;
			this->label13->Text = L"Cycle";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label14
			// 
			this->label14->BackColor = System::Drawing::Color::YellowGreen;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label14->Location = System::Drawing::Point(1070, 91);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(60, 24);
			this->label14->TabIndex = 24;
			this->label14->Text = L"Error";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(1073, 274);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(218, 109);
			this->textBox3->TabIndex = 27;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(1070, 254);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(59, 17);
			this->label15->TabIndex = 28;
			this->label15->Text = L"Weights";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FloralWhite;
			this->ClientSize = System::Drawing::Size(1303, 603);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label12);
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
		
		if (classValue == 2) {//single neuron delta

			if (classTag == 1) {
				classId = -1;//sýnýf id'si 1 den baþlayacak
			
				pen = gcnew Pen(Color::Red, 3.0f);
				int temp_x = (Convert::ToInt32(e->X));
				int temp_y = (Convert::ToInt32(e->Y));

				Instance temp = addInstanceOnPictureBox(classId, temp_x, temp_y, (pictureBox1->Height >> 1), (pictureBox1->Width >> 1));
				instances2->Add(temp);

				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);

				label3->Text = "x1 = " + Convert::ToString(temp.x1) + "    x2 = " + Convert::ToString(temp.x2);
				label4->Text = "Eklenen Örnek Sayýsý: " + Convert::ToString(instances2->Count) + " Class Id: " + Convert::ToString(classId);
				textBox1->Text += "Id: " + Convert::ToString(classId) + "   x1 = " + Convert::ToString(temp.x1) + "    x2 = " + Convert::ToString(temp.x2 + "\r\n");

			}
			else if (classTag == 2) {
				classId = 1;
				pen = gcnew Pen(Color::Blue, 3.0f);
				int temp_x = (Convert::ToInt32(e->X));
				int temp_y = (Convert::ToInt32(e->Y));

				Instance temp = addInstanceOnPictureBox(classId, temp_x, temp_y, (pictureBox1->Height >> 1), (pictureBox1->Width >> 1));
				instances2->Add(temp);

				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);


				label3->Text = "x1 = " + Convert::ToString(temp.x1) + "    x2 = " + Convert::ToString(temp.x2);
				label4->Text = "Eklenen Örnek Sayýsý: " + Convert::ToString(instances2->Count) + " Class Id: " + Convert::ToString(classId);
				textBox1->Text += "Id: " + Convert::ToString(classId) + "   x1 = " + Convert::ToString(temp.x1) + "    x2 = " + Convert::ToString(temp.x2 + "\r\n");

			}
		}
		else if (classValue > 2) {//multi neuron or multi layer.

			if (classTag == 1) {
				classId = 1;//sýnýf id'si 1 den baþlayacak
				pen = gcnew Pen(Color::Red, 3.0f);
				
				int temp_x = (Convert::ToInt32(e->X));
				int temp_y = (Convert::ToInt32(e->Y));

				Instance temp = addInstanceOnPictureBox(classId, temp_x, temp_y, (pictureBox1->Height >> 1), (pictureBox1->Width >> 1));
				instances2->Add(temp);

				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);

				label3->Text = "x1 = " + Convert::ToString(temp.x1) + "    x2 = " + Convert::ToString(temp.x2);
				label4->Text = "Eklenen Örnek Sayýsý: " + Convert::ToString(instances2->Count) + " Class Id: " + Convert::ToString(classId);
				textBox1->Text += "Id: " + Convert::ToString(classId) + "   x1 = " + Convert::ToString(temp.x1) + "    x2 = " + Convert::ToString(temp.x2 + "\r\n");

			}
			else if (classTag == 2) {
				classId = 2;
				pen = gcnew Pen(Color::Blue, 3.0f);
				
				int temp_x = (Convert::ToInt32(e->X));
				int temp_y = (Convert::ToInt32(e->Y));

				Instance temp = addInstanceOnPictureBox(classId, temp_x, temp_y, (pictureBox1->Height >> 1), (pictureBox1->Width >> 1));
				instances2->Add(temp);

				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);


				label3->Text = "x1 = " + Convert::ToString(temp.x1) + "    x2 = " + Convert::ToString(temp.x2);
				label4->Text = "Eklenen Örnek Sayýsý: " + Convert::ToString(instances2->Count) + " Class Id: " + Convert::ToString(classId);
				textBox1->Text += "Id: " + Convert::ToString(classId) + "   x1 = " + Convert::ToString(temp.x1) + "    x2 = " + Convert::ToString(temp.x2 + "\r\n");

			}
			else if (classTag == 3) {
				classId = 3;
				pen = gcnew Pen(Color::Black, 3.0f);
				
				int temp_x = (Convert::ToInt32(e->X));
				int temp_y = (Convert::ToInt32(e->Y));

				Instance temp = addInstanceOnPictureBox(classId, temp_x, temp_y, (pictureBox1->Height >> 1), (pictureBox1->Width >> 1));
				instances2->Add(temp);

				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);


				label3->Text = "x1 = " + Convert::ToString(temp.x1) + "    x2 = " + Convert::ToString(temp.x2);
				label4->Text = "Eklenen Örnek Sayýsý: " + Convert::ToString(instances2->Count) + " Class Id: " + Convert::ToString(classId);
				textBox1->Text += "Id: " + Convert::ToString(classId) + "   x1 = " + Convert::ToString(temp.x1) + "    x2 = " + Convert::ToString(temp.x2 + "\r\n");

			}

		}


    }
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		//neural aðý hazýrla.Kullanýcý girilecek sýnýf sayýsýný seçer ve buradan aðý hazýrlar.
		button1->Enabled = true;
		button2->Enabled = false;
		button3->Enabled = false;
		classValue = Decimal::ToInt32(numericUpDown1->Value);//sýnýf sayýsý alýnýr
		numericUpDown1->Enabled = false;//sýnýfý seçtiren nümerik iptal edilir
		numericUpDown2->Enabled = true;//sýnýf etiket için oluþturulan nümerikup down aktif edilir.
		numericUpDown2->Value = 1;
		classTag = Decimal::ToInt32(numericUpDown2->Value);
		MessageBox::Show("PictureBox üzerindeki koordinat alanlarýna örnekleri týklayarak yerleþtiriniz.");
    }
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//seçimlerin onaylanmasý
		//kullanýcý tüm örnekleri girer.
		
		classId = -1;
		numericUpDown2->Enabled = false;
		button1->Enabled = false;
		button2->Enabled = true;
		button3->Enabled = false;
		totalInstanceSize = instances2->Count;//toplam örnek sayýsý
		constTotalInstanceSize = instances2->Count;//toplam örnek sayýsý ama bu sabit kalacak

		
		choosenError = System::Convert::ToDouble(comboBox2->SelectedItem->ToString());
		choosenCycle = System::Convert::ToInt32(comboBox1->SelectedItem->ToString());
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		numericUpDown1->Enabled = true;//ilk baþlarken sýnýf sayýsý seçilsin
		numericUpDown2->Enabled = false;
		button1->Enabled = false;
		button2->Enabled = false;
		button3->Enabled = true;
		instances2->Clear();
		pictureBox1->Refresh();
		classValue = 0;
	
		totalInstanceSize = 0;
		constTotalInstanceSize = 0;
		classId = 0;
		numericUpDown1->Enabled = true;
		numericUpDown2->Enabled = true;

		label3->Text = "x1 = 0  " + "  x2 = 0";
		label4->Text = "Eklenen Örney Sayýsý: 0 " + " Class Id: Unkown";
	
		
	}
	private: System::Void numericUpDown2_ValueChanged(System::Object^ sender, System::EventArgs^ e) {

		 classTag = Decimal::ToInt32(numericUpDown2->Value);//kullanýcý her deðiþince etiket seçilir.

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

		textBox3->Text += "w[0]: " + Convert::ToString(weight[0]) + "\r\nx[1]: " + Convert::ToString(weight[1]) + "\r\nx[2]: " + Convert::ToString(weight[2]);

	
		min_x = (this->pictureBox1->Width) / -2;
		min_y = YPoint(min_x, weight);
		max_x = (this->pictureBox1->Width) / 2;
		max_y = YPoint(max_x, weight);
		pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);

	}
	private: System::Void randomizeForMultiCatToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Pen^ pen = gcnew Pen(Color::Green, 3.0f);
		int* minMaxCoordinates = new int[classValue * 4];
		

		int Dim = 2;
		int size = (Dim + 1) * classValue;
		weight = new double[size];

		srand(time(0));
		for (int i = 0; i < size; i++) {
			weight[i] = ((double)rand() / (RAND_MAX));
			textBox3->Text += "w[" + Convert::ToString(i) + "]:" + Convert::ToString(weight[i]) + "\r\n ";
		}

		for (int i = 0; i < classValue; i++) {
			
			minMaxCoordinates[i*4] = (this->pictureBox1->Width) / -2;//min_x
			minMaxCoordinates[i*4+1] = YPoint2(minMaxCoordinates[i * 4],i,classValue,weight);        //min_y
			minMaxCoordinates[i*4+2] = (this->pictureBox1->Width) / 2;//max_x
			minMaxCoordinates[i*4+3] = YPoint2(minMaxCoordinates[i * 4 + 2],i,classValue, weight);         //max_y
		}

		for (int i = 0; i < classValue; i++) {
			System::Random^ rastgele = gcnew System::Random();
			Pen^ pen2 = gcnew Pen(System::Drawing::Color::FromArgb(rastgele->Next(256), rastgele->Next(256), rastgele->Next(256)), 3.0f);

			pictureBox1->CreateGraphics()->DrawLine(pen2, (pictureBox1->Width / 2) + minMaxCoordinates[i*4], (pictureBox1->Height / 2) - minMaxCoordinates[i*4 + 1], (pictureBox1->Width / 2) + minMaxCoordinates[i*4 + 2], (pictureBox1->Height / 2) - minMaxCoordinates[i*4 + 3]);

		}
	
	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		//exit form
		exit(-1);
	}
	private: System::Void perceptronToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {


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
				trainingIsDone[j] = perceptronLearning(instances2[j], weight, 0.1);
			}
				
			for (int k = 0; k < constTotalInstanceSize; k++)
				if (trainingIsDone[k] == 0)
					allCyclesDone = false;

			if (allCyclesDone) {
				delete[] trainingIsDone;
				break;
			}
				
		}

		textBox3->Text = "w[0]: " + Convert::ToString(weight[0]) + "\r\nx[1]: " + Convert::ToString(weight[1]) + "\r\nx[2]: " + Convert::ToString(weight[2]);
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



		double totalX = 0.0;
		double totalY = 0.0;

		for (int i = 0; i < constTotalInstanceSize; i++) {
			totalX += instances2[i].x1;
			totalY += instances2[i].x2;
		}

		double mean_X = totalX / constTotalInstanceSize;
		double mean_Y = totalY / constTotalInstanceSize;

		
		double totalX2 = 0.0;
		double totalY2 = 0.0;
		for (int i = 0; i < constTotalInstanceSize; i++) {
			totalX2 += pow(instances2[i].x1 - mean_X, 2);
			totalY2 += pow(instances2[i].x2 - mean_Y, 2);
		}

		double standartDev_X = sqrt(totalX2 / (constTotalInstanceSize-1));
		double standartDev_Y = sqrt(totalY2 / (constTotalInstanceSize - 1));

		for (int i = 0; i < constTotalInstanceSize; i++) {

			instances2[i] = batchNormalization(instances2[i],mean_X,standartDev_X,mean_Y,standartDev_Y);
			textBox2->Text += "Id: " + Convert::ToString(instances2[i].id) + "   x1 = " + Convert::ToString(instances2[i].x1) + "    x2 = " + Convert::ToString(instances2[i].x2 + "\r\n");
		}



	

		int min_x, max_x, min_y, max_y;
	
		int totalCycleCount = 0;

		double error = 0.0;


		while (true) {

			error = 0.0;
			for (int i= 0; i < constTotalInstanceSize; i++) {
				error += deltaLearning(instances2[i], weight, 0.1);
			}
			totalCycleCount++;

			double err = (error / constTotalInstanceSize);
			
			
			
			if (err < choosenError || totalCycleCount == choosenCycle) {
				break;
			}
		}

		pictureBox1->Refresh();

		for (int i = 0; i < constTotalInstanceSize; i++) {
			
			if (instances2[i].id == -1) {
				pen = gcnew Pen(Color::Red, 3.0f);

			}
			else if (instances2[i].id == 1) {
				pen = gcnew Pen(Color::Blue, 3.0f);
			}
			int x = instances2[i].x1*30 + (pictureBox1->Width >> 1);
			int y = (pictureBox1->Height >> 1) - instances2[i].x2*30;
			
			pictureBox1->CreateGraphics()->DrawLine(pen, x - 5, y, x + 5, y);
			pictureBox1->CreateGraphics()->DrawLine(pen, x, y - 5, x, y + 5);
		}
	
		textBox3->Text = "w[0]: " + Convert::ToString(weight[0]) + "\r\nx[1]: " + Convert::ToString(weight[1]) + "\r\nx[2]: " + Convert::ToString(weight[2]);
		label8->Text = "Total Cycle Count = " + System::Convert::ToString(totalCycleCount);
		label9->Text = "Error = " + System::Convert::ToString(error/constTotalInstanceSize);


		min_x = (this->pictureBox1->Width) / -2;
		min_y = YPoint(min_x, weight);
		max_x = (this->pictureBox1->Width) / 2;
		max_y = YPoint(max_x, weight);

		pen->Color = Color::Purple;
		pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);

	}
	private: System::Void multiCatSLDeltaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		int neuronNum = classValue;

		double totalX = 0.0;
		double totalY = 0.0;

		for (int i = 0; i < constTotalInstanceSize; i++) {
			totalX += instances2[i].x1;
			totalY += instances2[i].x2;
		}

		double mean_X = totalX / constTotalInstanceSize;
		double mean_Y = totalY / constTotalInstanceSize;


		double totalX2 = 0.0;
		double totalY2 = 0.0;
		for (int i = 0; i < constTotalInstanceSize; i++) {
			totalX2 += pow(instances2[i].x1 - mean_X, 2);
			totalY2 += pow(instances2[i].x2 - mean_Y, 2);
		}

		double standartDev_X = sqrt(totalX2 / (constTotalInstanceSize - 1));
		double standartDev_Y = sqrt(totalY2 / (constTotalInstanceSize - 1));

		for (int i = 0; i < constTotalInstanceSize; i++) {

			instances2[i] = batchNormalization(instances2[i], mean_X, standartDev_X, mean_Y, standartDev_Y);
			textBox2->Text += "Id: " + Convert::ToString(instances2[i].id) + "   x1 = " + Convert::ToString(instances2[i].x1) + "    x2 = " + Convert::ToString(instances2[i].x2 + "\r\n");
		}

		int min_x, max_x, min_y, max_y;

		int totalCycleCount = 0;

		double error1,error2,error3 = 0.0;

		int Dim =  classValue;

		while (true) {

			error1, error2, error3 = 0.0;
			for (int i = 0; i < constTotalInstanceSize; i++) {

				if (instances2[i].id == 1) {

					error1 += createNeuron(instances2[i], weight, 0, Dim, 1, 1);
					error2 += createNeuron(instances2[i], weight, 1, Dim, 1, -1);
					error3 += createNeuron(instances2[i], weight, 2, Dim, 1, -1);
				}
				else if (instances2[i].id == 2) {
					error1 += createNeuron(instances2[i], weight, 0, Dim, 1, -1);
					error2 += createNeuron(instances2[i], weight, 1, Dim, 1, 1);
					error3 += createNeuron(instances2[i], weight, 2, Dim, 1, -1);
				}
				else if (instances2[i].id == 3) {
					error1 += createNeuron(instances2[i], weight, 0, Dim, 1, -1);
					error2 += createNeuron(instances2[i], weight, 1, Dim, 1, -1);
					error3 += createNeuron(instances2[i], weight, 2, Dim, 1, 1);
				}

			}
			totalCycleCount++;


			double err = ((error1 + error2 + error3) / pow(constTotalInstanceSize, 3));

			if (err < choosenError || totalCycleCount == choosenCycle) {
				label9->Text = "Error = " + System::Convert::ToString(err);
				break;
			}
		}
		pictureBox1->Refresh();

		for (int i = 0; i < constTotalInstanceSize; i++) {

			if (instances2[i].id == 1) {
				pen = gcnew Pen(Color::Red, 3.0f);

			}
			else if (instances2[i].id == 2) {
				pen = gcnew Pen(Color::Blue, 3.0f);
			}
			else if (instances2[i].id == 3) {
				pen = gcnew Pen(Color::Black, 3.0f);
			}
			int x = instances2[i].x1 * 30 + (pictureBox1->Width >> 1);
			int y = (pictureBox1->Height >> 1) - instances2[i].x2 * 30;

			pictureBox1->CreateGraphics()->DrawLine(pen, x - 5, y, x + 5, y);
			pictureBox1->CreateGraphics()->DrawLine(pen, x, y - 5, x, y + 5);
		}

		//ayýran doðrularýn çizimi
		int* minMaxCoordinates = new int[classValue * 4];
		
		colors->Add(Color::Red);
		colors->Add(Color::Blue);
		colors->Add(Color::Black);
		for (int i = 0; i < classValue; i++) {

			minMaxCoordinates[i * 4] = (this->pictureBox1->Width) / -2;//min_x
			minMaxCoordinates[i * 4 + 1] = YPoint2(minMaxCoordinates[i * 4], i, classValue, weight);        //min_y
			minMaxCoordinates[i * 4 + 2] = (this->pictureBox1->Width) / 2;//max_x
			minMaxCoordinates[i * 4 + 3] = YPoint2(minMaxCoordinates[i * 4 + 2], i, classValue, weight);         //max_y

			Pen^ pen2 = gcnew Pen(colors[i], 3.0f);

			pictureBox1->CreateGraphics()->DrawLine(pen2, (pictureBox1->Width / 2) + minMaxCoordinates[i * 4], (pictureBox1->Height / 2) - minMaxCoordinates[i * 4 + 1], (pictureBox1->Width / 2) + minMaxCoordinates[i * 4 + 2], (pictureBox1->Height / 2) - minMaxCoordinates[i * 4 + 3]);

		}

		int size = (2 + 1) * classValue;
		textBox3->Text = "";
		for (int i = 0; i < size; i++) {
		
			textBox3->Text += "w[" + Convert::ToString(i) + "]:" + Convert::ToString(weight[i]) + "\r\n ";
		}

		label8->Text = "Total Cycle Count = " + System::Convert::ToString(totalCycleCount);

		
	}

};
}

