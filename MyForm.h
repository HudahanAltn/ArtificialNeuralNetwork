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
#include <fstream>
#include <string>
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
			 numericUpDown3->Enabled = false;
			 numericUpDown4->Enabled = false;
			 button1->Enabled = false;
			 button2->Enabled = false;
			 button3->Enabled = true;
			//
			label3->Text = "";
			label4->Text = "";
			

			pen = gcnew Pen(Color::Red, 3.0f);//örnek ilk baþta kýrmýzý renli olacak
			classValue = classTag =  totalInstanceSize = constTotalInstanceSize = classId =  choosenCycle = 0;
			choosenError =  0.0;
			instances = gcnew List<Instance>();
			instances2 = gcnew List<Instance>();
			colors = gcnew List<Color>();
			chart1->Visible = false;
			momentum = false;
		}

	public:
		Pen^ pen;//sýnýftaki örneklerin picturebox'ta görünmesini saðlayacak olan kalem nesnesi.
		Int32 classValue;//sýnýf sayýsý
		Int32 classTag;//sýnýfýn etiketi(1,2,3,4,5,6,7,8,9,10)
		Int32 middleLayerNeuronNumber;
		Int32 outLayerNeuronNumber;
		List<Instance>^ instances;// ekrana týklanan noktalarý tutacak yani örneklerin listesi.
		List<Instance>^ instances2;// ekrana týklanan noktalarý kopyasýný tutacak yani örneklerin listesi.
		List<Color>^ colors;
		int totalInstanceSize, constTotalInstanceSize;//toplam örnek sayýsý 
		int classId;//her sýnýfýn eþþiz ýd'si olmalýdýr.
		double* weightMiddle;
		double* weightOut;
		double choosenError;
		double* mean;
		double* standartDev;
		float* biasMiddle;
		float* biasOut;
		int choosenCycle;
		bool momentum;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ continueLearningToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ readWeightToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ readInstancesToolStripMenuItem;
	public:
		double* mFnetInstances;

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
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ToolStripMenuItem^ randomizeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::ComponentModel::Container ^components;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::ToolStripMenuItem^ multiLayerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ trainingToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ testingToolStripMenuItem1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown4;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::ToolStripMenuItem^ errorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ showErrorToolStripMenuItem;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarýmcý desteði için gerekli metot - bu metodun 
		///içeriðini kod düzenleyici ile deðiþtirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ýnitializationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->randomizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->multiLayerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testingToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->continueLearningToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->errorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showErrorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
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
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->readWeightToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readInstancesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->Location = System::Drawing::Point(0, 48);
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
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->processToolStripMenuItem,
					this->multiLayerToolStripMenuItem, this->errorToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1924, 28);
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
					this->exitToolStripMenuItem, this->readWeightToolStripMenuItem, this->readInstancesToolStripMenuItem
			});
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
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// multiLayerToolStripMenuItem
			// 
			this->multiLayerToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->trainingToolStripMenuItem1,
					this->testingToolStripMenuItem1, this->continueLearningToolStripMenuItem
			});
			this->multiLayerToolStripMenuItem->Name = L"multiLayerToolStripMenuItem";
			this->multiLayerToolStripMenuItem->Size = System::Drawing::Size(92, 24);
			this->multiLayerToolStripMenuItem->Text = L"MultiLayer";
			// 
			// trainingToolStripMenuItem1
			// 
			this->trainingToolStripMenuItem1->Name = L"trainingToolStripMenuItem1";
			this->trainingToolStripMenuItem1->Size = System::Drawing::Size(224, 26);
			this->trainingToolStripMenuItem1->Text = L"Training";
			this->trainingToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::trainingToolStripMenuItem1_Click);
			// 
			// testingToolStripMenuItem1
			// 
			this->testingToolStripMenuItem1->Name = L"testingToolStripMenuItem1";
			this->testingToolStripMenuItem1->Size = System::Drawing::Size(224, 26);
			this->testingToolStripMenuItem1->Text = L"Testing";
			this->testingToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::testingToolStripMenuItem1_Click);
			// 
			// continueLearningToolStripMenuItem
			// 
			this->continueLearningToolStripMenuItem->Name = L"continueLearningToolStripMenuItem";
			this->continueLearningToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->continueLearningToolStripMenuItem->Text = L"ContinueLearning";
			this->continueLearningToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::continueLearningToolStripMenuItem_Click);
			// 
			// errorToolStripMenuItem
			// 
			this->errorToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->showErrorToolStripMenuItem });
			this->errorToolStripMenuItem->Name = L"errorToolStripMenuItem";
			this->errorToolStripMenuItem->Size = System::Drawing::Size(55, 24);
			this->errorToolStripMenuItem->Text = L"Error";
			// 
			// showErrorToolStripMenuItem
			// 
			this->showErrorToolStripMenuItem->Name = L"showErrorToolStripMenuItem";
			this->showErrorToolStripMenuItem->Size = System::Drawing::Size(160, 26);
			this->showErrorToolStripMenuItem->Text = L"ShowError";
			this->showErrorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::showErrorToolStripMenuItem_Click);
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
			this->label1->BackColor = System::Drawing::Color::PaleGoldenrod;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label1->Location = System::Drawing::Point(1360, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(235, 22);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Sýnýf Sayýsý";
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::PaleGoldenrod;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->Location = System::Drawing::Point(1360, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(235, 22);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Sýnýf Etiketi";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(1601, 32);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 22);
			this->numericUpDown1->TabIndex = 26;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(1601, 71);
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
			this->button1->Location = System::Drawing::Point(1360, 222);
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
			this->button2->Location = System::Drawing::Point(1638, 222);
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
			this->label3->Location = System::Drawing::Point(1571, 265);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"x1 = 0    x2 = 0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(1357, 298);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(278, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Eklenen Örnek Sayýsý: 0  Class Id: Unkown ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(1361, 329);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(143, 17);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Total Cycle Count = 0";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(1361, 357);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(64, 17);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Error = 0";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(1370, 422);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(217, 181);
			this->textBox1->TabIndex = 15;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(1689, 422);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(215, 181);
			this->textBox2->TabIndex = 16;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(1367, 398);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(63, 17);
			this->label10->TabIndex = 17;
			this->label10->Text = L"Örnekler";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(1686, 398);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(130, 17);
			this->label11->TabIndex = 18;
			this->label11->Text = L"Normalize Örnekler";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(1358, 265);
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
			this->button3->Location = System::Drawing::Point(1360, 172);
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
			this->comboBox1->Location = System::Drawing::Point(1793, 33);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->Text = L"10000";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(5) { 0.1, 0.01, 0.001, 0.0001, 1E-05 });
			this->comboBox2->Location = System::Drawing::Point(1793, 71);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 24);
			this->comboBox2->TabIndex = 0;
			this->comboBox2->Text = L"0.1";
			// 
			// label13
			// 
			this->label13->BackColor = System::Drawing::Color::YellowGreen;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label13->Location = System::Drawing::Point(1727, 33);
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
			this->label14->Location = System::Drawing::Point(1727, 71);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(60, 24);
			this->label14->TabIndex = 24;
			this->label14->Text = L"Error";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(1689, 285);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(218, 109);
			this->textBox3->TabIndex = 27;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(1686, 265);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(59, 17);
			this->label15->TabIndex = 28;
			this->label15->Text = L"Weights";
			// 
			// label16
			// 
			this->label16->BackColor = System::Drawing::Color::PaleGoldenrod;
			this->label16->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label16->Location = System::Drawing::Point(1092, 122);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(0, 0);
			this->label16->TabIndex = 29;
			this->label16->Text = L"Çýkýþ Katman Nöron Sayýsý";
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::Color::PaleGoldenrod;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label5->Location = System::Drawing::Point(1360, 104);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(235, 23);
			this->label5->TabIndex = 30;
			this->label5->Text = L"Ara Katman Nöron Sayýsý";
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::Color::PaleGoldenrod;
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label6->Location = System::Drawing::Point(1360, 138);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(235, 23);
			this->label6->TabIndex = 31;
			this->label6->Text = L"Çýkýþ Katman Nöron Sayýsý";
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(1601, 104);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDown3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(120, 22);
			this->numericUpDown3->TabIndex = 32;
			this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown3->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown3_ValueChanged);
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(1601, 138);
			this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDown4->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(120, 22);
			this->numericUpDown4->TabIndex = 33;
			this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown4->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown4_ValueChanged);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox2->Location = System::Drawing::Point(684, 48);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(500, 500);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 34;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox2_Paint);
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(1345, 263);
			this->chart1->Name = L"chart1";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(569, 340);
			this->chart1->TabIndex = 35;
			this->chart1->Text = L"chart1";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(1792, 107);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(99, 21);
			this->checkBox1->TabIndex = 36;
			this->checkBox1->Text = L"Momentum";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// readWeightToolStripMenuItem
			// 
			this->readWeightToolStripMenuItem->Name = L"readWeightToolStripMenuItem";
			this->readWeightToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->readWeightToolStripMenuItem->Text = L"ReadWeight";
			this->readWeightToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::readWeightToolStripMenuItem_Click);
			// 
			// readInstancesToolStripMenuItem
			// 
			this->readInstancesToolStripMenuItem->Name = L"readInstancesToolStripMenuItem";
			this->readInstancesToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->readInstancesToolStripMenuItem->Text = L"ReadInstances";
			this->readInstancesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::readInstancesToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::FloralWhite;
			this->ClientSize = System::Drawing::Size(1924, 603);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->numericUpDown4);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label16);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
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
				instances->Add(temp);
				instances2->Add(temp);

				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);

				label3->Text = "x1 = " + Convert::ToString(temp.x1) + "    x2 = " + Convert::ToString(temp.x2);
				label4->Text = "Eklenen Örnek Sayýsý: " + Convert::ToString(instances->Count) + " Class Id: " + Convert::ToString(classId);
				textBox1->Text += "Id: " + Convert::ToString(classId) + "   x1 = " + Convert::ToString(temp.x1) + "    x2 = " + Convert::ToString(temp.x2 + "\r\n");

			}
			else if (classTag == 2) {
				classId = 1;
				pen = gcnew Pen(Color::Blue, 3.0f);
				int temp_x = (Convert::ToInt32(e->X));
				int temp_y = (Convert::ToInt32(e->Y));

				Instance temp = addInstanceOnPictureBox(classId, temp_x, temp_y, (pictureBox1->Height >> 1), (pictureBox1->Width >> 1));
				instances->Add(temp);
				instances2->Add(temp);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);


				label3->Text = "x1 = " + Convert::ToString(temp.x1) + "    x2 = " + Convert::ToString(temp.x2);
				label4->Text = "Eklenen Örnek Sayýsý: " + Convert::ToString(instances->Count) + " Class Id: " + Convert::ToString(classId);
				textBox1->Text += "Id: " + Convert::ToString(classId) + "   x1 = " + Convert::ToString(temp.x1) + "    x2 = " + Convert::ToString(temp.x2 + "\r\n");

			}
		}
		
    }

	private: System::Void pictureBox2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		Pen^ pen = gcnew Pen(Color::Gray, 2.5f);
		int center_width, center_height;
		center_width = (int)(pictureBox1->Width / 2);
		center_height = (int)(pictureBox1->Height / 2);
		e->Graphics->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);
		e->Graphics->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		//neural aðý hazýrla.Kullanýcý girilecek sýnýf sayýsýný seçer ve buradan aðý hazýrlar.
		button1->Enabled = true;
		button2->Enabled = false;
		button3->Enabled = false;
		classValue = Decimal::ToInt32(numericUpDown1->Value);//sýnýf sayýsý alýnýr
		numericUpDown1->Enabled = false;//sýnýfý seçtiren nümerik iptal edilir
		numericUpDown2->Enabled = true;//sýnýf etiket için oluþturulan nümerikup down aktif edilir.
		numericUpDown3->Enabled = true;
		numericUpDown4->Enabled = true;
		comboBox1->Enabled = false;
		comboBox2->Enabled = false;
		numericUpDown2->Value = 1;
		classTag = Decimal::ToInt32(numericUpDown2->Value);
		MessageBox::Show("PictureBox üzerindeki koordinat alanlarýna örnekleri týklayarak yerleþtiriniz.");
    }
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//seçimlerin onaylanmasý
		//kullanýcý tüm örnekleri girer.
		
		classId = -1;
		numericUpDown2->Enabled = false;
		numericUpDown3->Enabled = false;
		numericUpDown4->Enabled = false;
		button1->Enabled = false;
		button2->Enabled = true;
		button3->Enabled = false;
		totalInstanceSize = instances->Count;//toplam örnek sayýsý
		constTotalInstanceSize = instances->Count;//toplam örnek sayýsý ama bu sabit kalacak

		
		choosenError = System::Convert::ToDouble(comboBox2->SelectedItem->ToString());
		choosenCycle = System::Convert::ToInt32(comboBox1->SelectedItem->ToString());
		outLayerNeuronNumber = Decimal::ToInt32(numericUpDown4->Value);//çýkýþ katmandaki noron sayýsý
		middleLayerNeuronNumber = Decimal::ToInt32(numericUpDown3->Value);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		//tekrar
		numericUpDown1->Enabled = true;//ilk baþlarken sýnýf sayýsý seçilsin
		numericUpDown3->Enabled = false;//ara katman noron sayýsý seçilsin
		numericUpDown4->Enabled = false;//cýkýs katman noron sayýsý seçilsin
		numericUpDown2->Enabled = false;
		comboBox1->Enabled = true;
		comboBox2->Enabled = true;

		button1->Enabled = false;
		button2->Enabled = false;
		button3->Enabled = true;
		instances->Clear();
		pictureBox1->Image = nullptr;
		pictureBox1->Refresh();
		pictureBox2->Refresh();
		chart1->Series->Clear();
		System::Windows::Forms::DataVisualization::Charting::Series^ yeniSeri = gcnew System::Windows::Forms::DataVisualization::Charting::Series();
		yeniSeri->Name = "Series1";
		chart1->Series->Add(yeniSeri);
		yeniSeri->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;

		classValue = 0;
	
		totalInstanceSize = 0;
		constTotalInstanceSize = 0;
		classId = 0;
		classValue = 0;//sýnýf sayýsý
		
		middleLayerNeuronNumber=2;
		outLayerNeuronNumber=1;
		instances->Clear();// ekrana týklanan noktalarý tutacak yani örneklerin listesi.
		instances2->Clear();// ekrana týklanan noktalarý kopyasýný tutacak yani örneklerin listesi.
		
		delete[] weightMiddle;
		delete[] weightOut;
		delete[] biasMiddle;
		delete[] biasOut;
		

		choosenCycle = 0;
		choosenError = 0;
		textBox3->Text = "";
		label3->Text = "x1 = 0  " + "  x2 = 0";
		label4->Text = "Eklenen Örney Sayýsý: 0 " + " Class Id: Unkown";
		label8->Text = "Total Cycle Count = 0";
		label9->Text = "Error = 0";
		
	}
	private: System::Void numericUpDown2_ValueChanged(System::Object^ sender, System::EventArgs^ e) {

		 classTag = Decimal::ToInt32(numericUpDown2->Value);//kullanýcý her deðiþince etiket seçilir.

	}
	private: System::Void numericUpDown3_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		middleLayerNeuronNumber = Decimal::ToInt32(numericUpDown3->Value);//ara katmandaki nöron sayýsý
	}
	private: System::Void numericUpDown4_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		outLayerNeuronNumber = Decimal::ToInt32(numericUpDown4->Value);//çýkýþ katmandaki noron sayýsý

	}
	private: System::Void randomizeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		//katmanlara rastgele aðýrlýk atamalarý.
		
		int Dim = 3;
		int middleLayerSize = Dim * middleLayerNeuronNumber;
		int outLayerSize = (middleLayerNeuronNumber + 1) * outLayerNeuronNumber;
		
		weightMiddle = new double[middleLayerSize];
		weightOut = new double[outLayerSize];

		srand(time(0));
		textBox3->Text += "WeightMiddle:\r\n\n";
		for (int i = 0; i < middleLayerSize; i++) {
			weightMiddle[i] = ((double)rand() / (RAND_MAX));
			textBox3->Text += "w[" + Convert::ToString(i) + "]:" + Convert::ToString(weightMiddle[i]) + "\r\n ";
		}
		textBox3->Text += "WeightOut:\r\n\n";
		for (int i = 0; i < outLayerSize; i++) {
			weightOut[i] = ((double)rand() / (RAND_MAX));
			textBox3->Text += "w[" + Convert::ToString(i) + "]:" + Convert::ToString(weightOut[i]) + "\r\n ";
		}
		
		biasMiddle = new float[middleLayerNeuronNumber];
		biasOut = new float[outLayerNeuronNumber];
		

		//bias deðerleri ayrý dizide tuttum.
		for (int i = 0; i < middleLayerNeuronNumber; i++) {
			biasMiddle[i] = 0;
		}
		for (int i = 0; i < outLayerNeuronNumber; i++) {
			biasOut[i] = 0; 
		}
		
	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		//exit form
		exit(-1);
	}
	private: System::Void trainingToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {

		{
			double totalX = 0.0;
			double totalY = 0.0;

			for (int i = 0; i < constTotalInstanceSize; i++) {
				totalX += instances[i].x1;
				totalY += instances[i].x2;
			}

			double mean_X = totalX / constTotalInstanceSize;
			double mean_Y = totalY / constTotalInstanceSize;

			mean = new double[2];
			mean[0] = mean_X;
			mean[1] = mean_Y;

			double totalX2 = 0.0;
			double totalY2 = 0.0;

			for (int i = 0; i < constTotalInstanceSize; i++) {
				totalX2 += pow(instances[i].x1 - mean_X, 2);
				totalY2 += pow(instances[i].x2 - mean_Y, 2);
			}

			double standartDev_X = sqrt(totalX2 / (constTotalInstanceSize - 1));
			double standartDev_Y = sqrt(totalY2 / (constTotalInstanceSize - 1));

			standartDev = new double[2];
			standartDev[0] = standartDev_X;
			standartDev[1] = standartDev_Y;
			for (int i = 0; i < constTotalInstanceSize; i++) {

				instances[i] = batchNormalization(instances[i], mean_X, standartDev_X, mean_Y, standartDev_Y);
				textBox2->Text += "Id: " + Convert::ToString(instances[i].id) + "   x1 = " + Convert::ToString(instances[i].x1) + "    x2 = " + Convert::ToString(instances[i].x2 + "\r\n");
			}
		}
		
		int totalCycleCount = 0;
		double error = 0.0;

		//double* mFNetArray = new double[middleLayerNeuronNumber];//middle layer noronlarýn f(net) ini tutacak dizi
		//double* oFNetArray = new double[outLayerNeuronNumber];//out layer noronlarýn f(net) ini tutacak dizi
	
	
		chart1->Series["Series1"]->Points->Clear();
		while (true) {
			double* mFNetArray = new double[middleLayerNeuronNumber];//middle layer noronlarýn f(net) ini tutacak dizi
			double* oFNetArray = new double[outLayerNeuronNumber];//out layer noronlarýn f(net) ini tutacak dizi

			error = 0.0;
			
			for (int i = 0; i < constTotalInstanceSize; i++) {
				error += feedForward(instances[i], weightMiddle, weightOut, 1, mFNetArray, oFNetArray, middleLayerNeuronNumber, outLayerNeuronNumber);
				backForward(instances[i],momentum, weightMiddle, weightOut, 1, mFNetArray, oFNetArray, middleLayerNeuronNumber, outLayerNeuronNumber);
				
			}

			delete[] mFNetArray;
			delete[] oFNetArray;

			totalCycleCount++;

			double err = (error / constTotalInstanceSize);

			if (choosenCycle > 10000) {
				if (totalCycleCount % 10000 == 0) {
					chart1->Series["Series1"]->Points->AddXY(totalCycleCount, err);
				}
	
			}else {
				chart1->Series["Series1"]->Points->AddXY(totalCycleCount, err);
			}
			
			if (err < choosenError || totalCycleCount == choosenCycle) {
				break;
			}
		}

		for(int i = 0; i < middleLayerNeuronNumber; i++) {
			biasMiddle[i] = weightMiddle[i * 3 + 2];
		}

		for (int i = 0; i < outLayerNeuronNumber; i++) {
			biasOut[i] = weightOut[i * (middleLayerNeuronNumber + 1) + middleLayerNeuronNumber];
		}

		pictureBox1->Refresh();

		label8->Text = "Total Cycle Count = " + System::Convert::ToString(totalCycleCount);
		label9->Text = "Error = " + System::Convert::ToString(error / constTotalInstanceSize);

	}
	private: System::Void testingToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		
			float* x = new float[2];
			pictureBox1->Refresh();
			int num, temp_x, temp_y;
			Bitmap^ surface = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			pictureBox1->Image = surface;
			Color c;
			for (int row = 0; row < pictureBox1->Height; row += 2) {
				for (int column = 0; column < pictureBox1->Width; column += 2) {
					x[0] = (float)(column - (pictureBox1->Width / 2));
					x[1] = (float)((pictureBox1->Height / 2) - row);
					x[0] = (float)(x[0] - mean[0]) / standartDev[0];
					x[1] = (float)(x[1] - mean[1]) / standartDev[1];
					num = MultiLayer_Test_Forward(x, weightMiddle, biasMiddle, weightOut, biasOut, 3, middleLayerNeuronNumber);
					switch (num) {
					case 0: c = Color::Red; break;
					case 1: c = Color::Blue; break;
					case 2: c = Color::Black; break;
					case 3: c = Color::Brown; break;
					case 4: c = Color::Orange; break;
					default: c = Color::Gray;
					}
					surface->SetPixel(column, row, c);
				}
			}

			Pen^ pen;
			MessageBox::Show("Örnekler cizilecek");
			for (int i = 0; i < constTotalInstanceSize; i++) {
				switch (int(instances[i].id)) {
				case -1: pen = gcnew Pen(Color::Red, 3.0f); break;
				case 1: pen = gcnew Pen(Color::Blue, 3.0f); break;
				case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
				case 3: pen = gcnew Pen(Color::Black, 3.0f); break;
				case 4: pen = gcnew Pen(Color::Brown, 3.0f); break;
				case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
				case 6: pen = gcnew Pen(Color::Gray, 3.0f); break;
				default: pen = gcnew Pen(Color::Blue, 3.0f);
				}//switch
				temp_x = int(instances2[i].x1 ) + pictureBox1->Width / 2;
				temp_y = pictureBox1->Height / 2 - int(instances2[i].x2 );
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
			}
		
		delete[] x;
		delete[] mean;
		delete[] standartDev;

	}
	private: System::Void showErrorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
		
		if (chart1->Visible) {
			chart1->Visible = false;
		}
		else {
			chart1->Visible = true;
		}
		
	}
	private: System::Void continueLearningToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		numericUpDown2->Enabled = true;
		button1->Enabled = true;
		pictureBox1->Refresh();
		chart1->Series->Clear();

		System::Windows::Forms::DataVisualization::Charting::Series^ yeniSeri = gcnew System::Windows::Forms::DataVisualization::Charting::Series();
		yeniSeri->Name = "Series1";
		chart1->Series->Add(yeniSeri);
		yeniSeri->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;

		int temp_x, temp_y;
		for (int i = 0; i < constTotalInstanceSize; i++) {
			switch (int(instances[i].id)) {
			case (-1): pen = gcnew Pen(Color::Red, 3.0f); break;
			case 1: pen = gcnew Pen(Color::Blue, 3.0f); break;
			case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
			case 3: pen = gcnew Pen(Color::Black, 3.0f); break;
			case 4: pen = gcnew Pen(Color::Brown, 3.0f); break;
			case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
			case 6: pen = gcnew Pen(Color::Gray, 3.0f); break;
			default: pen = gcnew Pen(Color::Green, 3.0f);
			}//switch
			temp_x = int(instances2[i].x1) + pictureBox1->Width / 2;
			temp_y = pictureBox1->Height / 2 - int(instances2[i].x2);
			pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
			pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
		}
		instances->Clear();

		for (int i = 0; i < constTotalInstanceSize; i++) {
			instances->Add(instances2[i]);
		}
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

		if (checkBox1->Checked) {
			momentum = true;
		}
		else {
			momentum = false;
		}
	}
	private: System::Void readWeightToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void readInstancesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
};
}

