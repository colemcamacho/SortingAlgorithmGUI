
#pragma once
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <chrono>
#include <string>

const int numElem = 280;
int sleepTime = 0;
time_t start, finish;
long product;

// This structure represents the data for a line. xsp = x starting position, xep = x ending position, ysp = y starting position, yep = y ending position
struct lines
{
	int xsp;
	int xep;
	int ysp;
	int yep;
};

// arr_lines is the main array for holding all of the line data, tmpLines is an array used for randomizing
struct lines arr_lines[numElem];
struct lines tmpLines[numElem];
// The sort method variable is used to decide which algorithm to use when pressing the start button. It starts off with a value of 1, for quick sort
int sortMethod = 1;
bool randomized = true;
bool beginning = true;

namespace GUIDataAlgorithmPersonalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ BQSort;
	private: System::Windows::Forms::Panel^ panel1;
	private: Drawing::Graphics^ g;
	private: System::Windows::Forms::Button^ BMrgSort;
	private: System::Windows::Forms::Button^ BInsrtSort;
	private: System::Windows::Forms::Button^ BBubbleSort;
	private: System::Windows::Forms::Button^ BSelectSort;
	private: System::Windows::Forms::Label^ LSpeed;

	private: System::Windows::Forms::Button^ BRandom;
	private: System::Windows::Forms::ListBox^ SlowTime;
	private: System::Windows::Forms::Button^ Start_Button;
	private: System::Windows::Forms::Label^ msL;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->BQSort = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->BMrgSort = (gcnew System::Windows::Forms::Button());
			this->BInsrtSort = (gcnew System::Windows::Forms::Button());
			this->BBubbleSort = (gcnew System::Windows::Forms::Button());
			this->BSelectSort = (gcnew System::Windows::Forms::Button());
			this->LSpeed = (gcnew System::Windows::Forms::Label());
			this->BRandom = (gcnew System::Windows::Forms::Button());
			this->SlowTime = (gcnew System::Windows::Forms::ListBox());
			this->Start_Button = (gcnew System::Windows::Forms::Button());
			this->msL = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(868, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(286, 709);
			this->label1->TabIndex = 0;
			this->label1->Text = resources->GetString(L"label1.Text");
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// BQSort
			// 
			this->BQSort->BackColor = System::Drawing::Color::White;
			this->BQSort->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->BQSort->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BQSort->Location = System::Drawing::Point(15, 12);
			this->BQSort->Name = L"BQSort";
			this->BQSort->Size = System::Drawing::Size(195, 57);
			this->BQSort->TabIndex = 1;
			this->BQSort->Text = L"Quick Sort";
			this->BQSort->UseVisualStyleBackColor = false;
			this->BQSort->Click += gcnew System::EventHandler(this, &MyForm::BQSort_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Location = System::Drawing::Point(12, 158);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(849, 432);
			this->panel1->TabIndex = 2;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// BMrgSort
			// 
			this->BMrgSort->BackColor = System::Drawing::Color::DarkGray;
			this->BMrgSort->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->BMrgSort->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BMrgSort->Location = System::Drawing::Point(216, 12);
			this->BMrgSort->Name = L"BMrgSort";
			this->BMrgSort->Size = System::Drawing::Size(212, 57);
			this->BMrgSort->TabIndex = 3;
			this->BMrgSort->Text = L"Merge Sort";
			this->BMrgSort->UseVisualStyleBackColor = false;
			this->BMrgSort->Click += gcnew System::EventHandler(this, &MyForm::BMrgSort_Click);
			// 
			// BInsrtSort
			// 
			this->BInsrtSort->BackColor = System::Drawing::Color::DarkGray;
			this->BInsrtSort->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->BInsrtSort->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BInsrtSort->Location = System::Drawing::Point(434, 12);
			this->BInsrtSort->Name = L"BInsrtSort";
			this->BInsrtSort->Size = System::Drawing::Size(224, 57);
			this->BInsrtSort->TabIndex = 4;
			this->BInsrtSort->Text = L"Insertion Sort";
			this->BInsrtSort->UseVisualStyleBackColor = false;
			this->BInsrtSort->Click += gcnew System::EventHandler(this, &MyForm::BInsrtSort_Click);
			// 
			// BBubbleSort
			// 
			this->BBubbleSort->BackColor = System::Drawing::Color::DarkGray;
			this->BBubbleSort->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->BBubbleSort->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BBubbleSort->Location = System::Drawing::Point(663, 12);
			this->BBubbleSort->Name = L"BBubbleSort";
			this->BBubbleSort->Size = System::Drawing::Size(198, 57);
			this->BBubbleSort->TabIndex = 5;
			this->BBubbleSort->Text = L"Bubble Sort";
			this->BBubbleSort->UseVisualStyleBackColor = false;
			this->BBubbleSort->Click += gcnew System::EventHandler(this, &MyForm::BBubbleSort_Click);
			// 
			// BSelectSort
			// 
			this->BSelectSort->BackColor = System::Drawing::Color::DarkGray;
			this->BSelectSort->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->BSelectSort->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BSelectSort->Location = System::Drawing::Point(15, 89);
			this->BSelectSort->Name = L"BSelectSort";
			this->BSelectSort->Size = System::Drawing::Size(195, 54);
			this->BSelectSort->TabIndex = 6;
			this->BSelectSort->Text = L"Selection Sort";
			this->BSelectSort->UseVisualStyleBackColor = false;
			this->BSelectSort->Click += gcnew System::EventHandler(this, &MyForm::BSelectSort_Click);
			// 
			// LSpeed
			// 
			this->LSpeed->AutoSize = true;
			this->LSpeed->Location = System::Drawing::Point(8, 594);
			this->LSpeed->Name = L"LSpeed";
			this->LSpeed->Size = System::Drawing::Size(60, 20);
			this->LSpeed->TabIndex = 8;
			this->LSpeed->Text = L"Speed:";
			// 
			// BRandom
			// 
			this->BRandom->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->BRandom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BRandom->Location = System::Drawing::Point(238, 612);
			this->BRandom->Name = L"BRandom";
			this->BRandom->Size = System::Drawing::Size(268, 89);
			this->BRandom->TabIndex = 9;
			this->BRandom->Text = L"Randomize";
			this->BRandom->UseVisualStyleBackColor = true;
			this->BRandom->Click += gcnew System::EventHandler(this, &MyForm::BRandom_Click);
			// 
			// SlowTime
			// 
			this->SlowTime->FormattingEnabled = true;
			this->SlowTime->ItemHeight = 20;
			this->SlowTime->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Fast", L"Quick", L"Moderate", L"Slow" });
			this->SlowTime->Location = System::Drawing::Point(12, 617);
			this->SlowTime->Name = L"SlowTime";
			this->SlowTime->Size = System::Drawing::Size(140, 84);
			this->SlowTime->TabIndex = 10;
			this->SlowTime->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::SlowTime_SelectedIndexChanged);
			// 
			// Start_Button
			// 
			this->Start_Button->BackColor = System::Drawing::Color::LimeGreen;
			this->Start_Button->FlatAppearance->BorderColor = System::Drawing::Color::LimeGreen;
			this->Start_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Start_Button->Location = System::Drawing::Point(554, 612);
			this->Start_Button->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Start_Button->Name = L"Start_Button";
			this->Start_Button->Size = System::Drawing::Size(308, 89);
			this->Start_Button->TabIndex = 11;
			this->Start_Button->Text = L"Start";
			this->Start_Button->UseVisualStyleBackColor = false;
			this->Start_Button->Click += gcnew System::EventHandler(this, &MyForm::Start_Button_Click);
			// 
			// msL
			// 
			this->msL->AutoSize = true;
			this->msL->Location = System::Drawing::Point(124, 594);
			this->msL->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->msL->Name = L"msL";
			this->msL->Size = System::Drawing::Size(30, 20);
			this->msL->TabIndex = 12;
			this->msL->Text = L"ms";
			this->msL->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1162, 720);
			this->Controls->Add(this->msL);
			this->Controls->Add(this->Start_Button);
			this->Controls->Add(this->SlowTime);
			this->Controls->Add(this->BRandom);
			this->Controls->Add(this->LSpeed);
			this->Controls->Add(this->BSelectSort);
			this->Controls->Add(this->BBubbleSort);
			this->Controls->Add(this->BInsrtSort);
			this->Controls->Add(this->BMrgSort);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->BQSort);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		}

		private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
			
		}

		private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			// To make the lines for the pannel, I use the Pen class to do so.
			g = panel1->CreateGraphics();
			Pen^ whitePen = gcnew Pen(Color::White);

			Point startPoint;
			Point endPoint;

			int yStart = 280;
			int len = 280;
			int width = 4;

			// this for loop sets up the data from largest to smallest 
			for (int i = 0; i < numElem; i++) {
				tmpLines[i].xsp = width;  // Fill array with data
				tmpLines[i].xep = width;
				tmpLines[i].ysp = yStart;
				tmpLines[i].yep = yStart - len;

				// g->DrawLine(redPen, startPoint, endPoint);  // Draw lines
				len = len - 1;
				width = width + 2;
			}


			// When at the beggining of the program, the code inside the if statement will randomize the data
			if (beginning == true) {
				int test[numElem];
				int swap_index;


				srand((unsigned int)time(NULL));
				for (int j = 0; j < numElem; j++)
				{
					if (tmpLines[j].xsp != -1) {
						swap_index = rand() % numElem;

						if (tmpLines[swap_index].xsp != -1) {
							arr_lines[j].xsp = tmpLines[j].xsp;
							arr_lines[j].xep = tmpLines[j].xep;
							arr_lines[j].ysp = tmpLines[swap_index].ysp;
							arr_lines[j].yep = tmpLines[swap_index].yep;

							startPoint.X = arr_lines[j].xsp;
							endPoint.X = arr_lines[j].xep;
							startPoint.Y = arr_lines[j].ysp;
							endPoint.Y = arr_lines[j].yep;

							g->DrawLine(whitePen, startPoint, endPoint);

							arr_lines[swap_index].xsp = tmpLines[swap_index].xsp;
							arr_lines[swap_index].xep = tmpLines[swap_index].xep;
							arr_lines[swap_index].ysp = tmpLines[j].ysp;
							arr_lines[swap_index].yep = tmpLines[j].yep;

							startPoint.X = arr_lines[swap_index].xsp;
							endPoint.X = arr_lines[swap_index].xep;
							startPoint.Y = arr_lines[swap_index].ysp;
							endPoint.Y = arr_lines[swap_index].yep;

							g->DrawLine(whitePen, startPoint, endPoint);
						}
						else {
							while (tmpLines[swap_index].xsp == -1) {
								swap_index = rand() % numElem;
							};
							arr_lines[j].xsp = tmpLines[j].xsp;
							arr_lines[j].xep = tmpLines[j].xep;
							arr_lines[j].ysp = tmpLines[swap_index].ysp;
							arr_lines[j].yep = tmpLines[swap_index].yep;

							startPoint.X = arr_lines[j].xsp;
							endPoint.X = arr_lines[j].xep;
							startPoint.Y = arr_lines[j].ysp;
							endPoint.Y = arr_lines[j].yep;

							g->DrawLine(whitePen, startPoint, endPoint);

							arr_lines[swap_index].xsp = tmpLines[swap_index].xsp;
							arr_lines[swap_index].xep = tmpLines[swap_index].xep;
							arr_lines[swap_index].ysp = tmpLines[j].ysp;
							arr_lines[swap_index].yep = tmpLines[j].yep;

							startPoint.X = arr_lines[swap_index].xsp;
							endPoint.X = arr_lines[swap_index].xep;
							startPoint.Y = arr_lines[swap_index].ysp;
							endPoint.Y = arr_lines[swap_index].yep;

							g->DrawLine(whitePen, startPoint, endPoint);
						}

						tmpLines[swap_index].xsp = -1;
						tmpLines[j].xsp = -1;
					}
					test[j] = -2;
				}
			}

			else {
				for (int i = 0; i < 280; i++) {
					startPoint.X = arr_lines[i].xsp;
					endPoint.X = arr_lines[i].xep;
					startPoint.Y = arr_lines[i].ysp;
					endPoint.Y = arr_lines[i].yep;
					g->DrawLine(whitePen, startPoint, endPoint);
				}
			}
			
			// Set up the temp array to be equal to the actual data
			for (int i = 0; i < 280; i++) {
				tmpLines[i].xsp = arr_lines[i].xsp;
				tmpLines[i].xep = arr_lines[i].xep;
				tmpLines[i].ysp = arr_lines[i].ysp;
				tmpLines[i].yep = arr_lines[i].yep;
			}
			beginning = false;
		}

		private: System::Void Start_Button_Click(System::Object^ sender, System::EventArgs^ e)
		{
			// Disable all of the elements in the program when the algorithms are running.
			this->Start_Button->Enabled = false;
			this->BQSort->Enabled = false;
			this->BMrgSort->Enabled = false;
			this->BSelectSort->Enabled = false;
			this->BInsrtSort->Enabled = false;
			this->BBubbleSort->Enabled = false;
			this->LSpeed->Enabled = false;
			this->SlowTime->Enabled = false;

			this->BRandom->BackColor = Color::DarkGray;
			this->SlowTime->BackColor = Color::DarkGray;

			// If the program isn't randomized, this will randomize the data before going into the algorithm
			if (randomized == false) {
				BRandom->PerformClick();
			}

			this->BRandom->Enabled = false;

			// This is the quick sort call
			if (sortMethod == 1) {
				label1->Text = "Quick Sort is in one of the Divide and Conquer sorting algorithms, meaning, it divides the problem into further sub problems, and rebuilds it back up to a sorted version. It works by choosing a partion, manipulating the other elements around that partition based on what's smaller or greater, and repeats that process on the numbers smaller and greater than that partition. This process repeats until each side of the partition has at most one element left. The Big O notation is O(log(n)).";
				auto begin = std::chrono::steady_clock::now();  // start timer
				MyQuicksort(arr_lines, 0, 279);
				auto end = std::chrono::steady_clock::now();  // end timer
				size_t elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
				std::string str = std::to_string(elapsed);
				String^ str2 = "Speed: " + gcnew String(str.c_str());
				LSpeed->Text = str2;

				randomized = false;

			}
			// This is the merge sort call
			else if (sortMethod == 2) {

				auto begin = std::chrono::steady_clock::now();  // start timer
				Mergesort(arr_lines, 0, 279);
				auto end = std::chrono::steady_clock::now();  // end timer
				size_t elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
				std::string str = std::to_string(elapsed);
				String^ str2 = "Speed: " + gcnew String(str.c_str());
				LSpeed->Text = str2;

				randomized = false;

			}
			// This is the insertion sort call
			else if (sortMethod == 3) {

				auto begin = std::chrono::steady_clock::now();  // start timer
				insertionSort(arr_lines, numElem);
				auto end = std::chrono::steady_clock::now();  // end timer
				size_t elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
				std::string str = std::to_string(elapsed);
				String^ str2 = "Speed: " + gcnew String(str.c_str());
				LSpeed->Text = str2;

				randomized = false;
			}
			// This is the bubble sort call
			else if (sortMethod == 4) {
				auto begin = std::chrono::steady_clock::now();  // start timer
				bubbleSort(arr_lines, numElem);
				auto end = std::chrono::steady_clock::now();  // end timer
				size_t elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
				std::string str = std::to_string(elapsed);
				String^ str2 = "Speed: " + gcnew String(str.c_str());
				LSpeed->Text = str2;

				randomized = false;
			}
			// This is the selection sort call
			else if (sortMethod == 5) {

				auto begin = std::chrono::steady_clock::now();  // start timer
				selectionSort(arr_lines, numElem);
				auto end = std::chrono::steady_clock::now();  // end timer
				size_t elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
				std::string str = std::to_string(elapsed);
				String^ str2 = "Speed: " + gcnew String(str.c_str());
				LSpeed->Text = str2;

				randomized = false;
			}

			// This re enables all of the buttons, etc. in the program
			this->BQSort->Enabled = true;
			this->BMrgSort->Enabled = true;
			this->BSelectSort->Enabled = true;
			this->BInsrtSort->Enabled = true;
			this->BBubbleSort->Enabled = true;
			this->BRandom->Enabled = true;
			this->LSpeed->Enabled = true;
			this->SlowTime->Enabled = true;

			this->Start_Button->Enabled = true;


			this->BRandom->BackColor = Color::White;
			this->SlowTime->BackColor = Color::White;
		}

		// This section is what handles all of the button clicks
		private: System::Void BQSort_Click(System::Object^ sender, System::EventArgs^ e) {
			sortMethod = 1; // Change the sort method
			label1->Text = "Quick Sort is a Divide and Conquer sorting algorithm, meaning, it divides the problem into further sub problems, and rebuilds it back up to a sorted version. It works by choosing a partion (in this case, the element farthest to the left), and moves the elements larger than the partition to the right of it. The algorithm then recursively repeats the process to each side of the partition until completion. This algorithm has a Big O notation is O(log(n)).";
			// Change the colors of the buttons to indicate which one is selected
			this->BQSort->BackColor = System::Drawing::Color::White;
			this->BMrgSort->BackColor = System::Drawing::Color::DarkGray;
			this->BInsrtSort->BackColor = System::Drawing::Color::DarkGray;
			this->BBubbleSort->BackColor = System::Drawing::Color::DarkGray;
			this->BSelectSort->BackColor = System::Drawing::Color::DarkGray;
		}

		private: System::Void BMrgSort_Click(System::Object^ sender, System::EventArgs^ e) {
			sortMethod = 2;
			label1->Text = "Merge Sort is a Divide and Conquer sorting algorithm, meaning it divides the problem into further sub problems and rebuilds it back into the sorted solution. Merge Sort takes an array of elements and splits the array in half and puts them into their own unique array. It recursively does this, until each array has at most one element. The algorithm then begins to put the array back together, one array by one array left to right, and sorting the data from smallest to largest while doing so. Eventually, this will lead to a fully sorted array. The Big O Notation for this algorithm is O(n log(n)).";
			this->BQSort->BackColor = System::Drawing::Color::DarkGray;
			this->BMrgSort->BackColor = System::Drawing::Color::White;
			this->BInsrtSort->BackColor = System::Drawing::Color::DarkGray;
			this->BBubbleSort->BackColor = System::Drawing::Color::DarkGray;
			this->BSelectSort->BackColor = System::Drawing::Color::DarkGray;
		}

		private: System::Void BInsrtSort_Click(System::Object^ sender, System::EventArgs^ e) {
			sortMethod = 3;
			label1->Text = "Insertion Sort is simple in comparison to the divide and conquer algorithms. Starting from the second element in the array, we compare all of the elements to the left of it, and place it in ascending order in that group. Once it has been placed in its correct position, we move onto the next variable. If it is, we swap the values, and check the value to the left of it again. This algorithm's Big O notation is O(n^2).";
			this->BQSort->BackColor = System::Drawing::Color::DarkGray;
			this->BMrgSort->BackColor = System::Drawing::Color::DarkGray;
			this->BInsrtSort->BackColor = System::Drawing::Color::White;
			this->BBubbleSort->BackColor = System::Drawing::Color::DarkGray;
			this->BSelectSort->BackColor = System::Drawing::Color::DarkGray;
		}

		private: System::Void BBubbleSort_Click(System::Object^ sender, System::EventArgs^ e) {
			sortMethod = 4;
			label1->Text = "Bubble Sort is simple in comparison to the the divide and conquer algorithms. Starting at the first element in an array, we compare all elements from the left to the right to find the largest element. Once it's found, we move the largest element all the way to right. The algorithm repeats the same thing, except that element will be placed to the left of the next largest element. The Big O Notation is O(n^2).";
			this->BQSort->BackColor = System::Drawing::Color::DarkGray;
			this->BMrgSort->BackColor = System::Drawing::Color::DarkGray;
			this->BInsrtSort->BackColor = System::Drawing::Color::DarkGray;
			this->BBubbleSort->BackColor = System::Drawing::Color::White;
			this->BSelectSort->BackColor = System::Drawing::Color::DarkGray;
		}

		private: System::Void BSelectSort_Click(System::Object^ sender, System::EventArgs^ e) {
			sortMethod = 5;
			label1->Text = "Selection Sort is simple in comparison to the divide and conquer sorting algorithms. Starting at the first element in an array, the algorithm looks for the smallest number to the left of this element. If one is found, swap elements. Move to the next element, and repeat the process. This ends when we reach the last element in the array. The Big O Notation for this algorithm is O(n^2).";
			this->BQSort->BackColor = System::Drawing::Color::DarkGray;
			this->BMrgSort->BackColor = System::Drawing::Color::DarkGray;
			this->BInsrtSort->BackColor = System::Drawing::Color::DarkGray;
			this->BBubbleSort->BackColor = System::Drawing::Color::DarkGray;
			this->BSelectSort->BackColor = System::Drawing::Color::White;
		}
		// This allows the user to choose how fast they want the program to run
		private: System::Void SlowTime_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			if (SlowTime->Text == "Fast") // Milliseconds
				sleepTime = 0;
			else if (SlowTime->Text == "Quick")
				sleepTime = 2;
			else if (SlowTime->Text == "Moderate")
				sleepTime = 4;
			else if (SlowTime->Text == "Slow")
				sleepTime = 6;
		}

		// This button allows the user to randomize the data when clicking the button
		private: System::Void BRandom_Click(System::Object^ sender, System::EventArgs^ e) {
			Pen^ blackPen = gcnew Pen(Color::Black);

			Point startPoint;
			Point endPoint;

			int yStart = 280;
			int len = 280;
			int width = 4;

			// Fill panel black
			BlackenPanel();

			Pen^ whitePen = gcnew Pen(Color::White);

			// Shuffle Array - No duplicate random index values allowed
			int swap_index;
			srand((unsigned int)time(NULL));
			for (int j = 0; j < numElem; j++)
			{
				if (tmpLines[j].xsp != -1) {
					swap_index = rand() % numElem;

					if (tmpLines[swap_index].xsp != -1) {
						arr_lines[j].xsp = tmpLines[j].xsp;
						arr_lines[j].xep = tmpLines[j].xep;
						arr_lines[j].ysp = tmpLines[swap_index].ysp;
						arr_lines[j].yep = tmpLines[swap_index].yep;

						startPoint.X = arr_lines[j].xsp;
						endPoint.X = arr_lines[j].xep;
						startPoint.Y = arr_lines[j].ysp;
						endPoint.Y = arr_lines[j].yep;

						g->DrawLine(whitePen, startPoint, endPoint);

						arr_lines[swap_index].xsp = tmpLines[swap_index].xsp;
						arr_lines[swap_index].xep = tmpLines[swap_index].xep;
						arr_lines[swap_index].ysp = tmpLines[j].ysp;
						arr_lines[swap_index].yep = tmpLines[j].yep;

						startPoint.X = arr_lines[swap_index].xsp;
						endPoint.X = arr_lines[swap_index].xep;
						startPoint.Y = arr_lines[swap_index].ysp;
						endPoint.Y = arr_lines[swap_index].yep;

						g->DrawLine(whitePen, startPoint, endPoint);
					}
					else {
						while (tmpLines[swap_index].xsp == -1) {
							swap_index = rand() % numElem;
						};
						arr_lines[j].xsp = tmpLines[j].xsp;
						arr_lines[j].xep = tmpLines[j].xep;
						arr_lines[j].ysp = tmpLines[swap_index].ysp;
						arr_lines[j].yep = tmpLines[swap_index].yep;

						startPoint.X = arr_lines[j].xsp;
						endPoint.X = arr_lines[j].xep;
						startPoint.Y = arr_lines[j].ysp;
						endPoint.Y = arr_lines[j].yep;
						
						g->DrawLine(whitePen, startPoint, endPoint);

						arr_lines[swap_index].xsp = tmpLines[swap_index].xsp;
						arr_lines[swap_index].xep = tmpLines[swap_index].xep;
						arr_lines[swap_index].ysp = tmpLines[j].ysp;
						arr_lines[swap_index].yep = tmpLines[j].yep;

						startPoint.X = arr_lines[swap_index].xsp;
						endPoint.X = arr_lines[swap_index].xep;
						startPoint.Y = arr_lines[swap_index].ysp;
						endPoint.Y = arr_lines[swap_index].yep;
						
						g->DrawLine(whitePen, startPoint, endPoint);
					}

					tmpLines[swap_index].xsp = -1;
					tmpLines[j].xsp = -1;
				}
			}
			// Set temp array = to working array - Needed to randomize array
			for (int i = 0; i < 280; i++) {
				tmpLines[i].xsp = arr_lines[i].xsp;
				tmpLines[i].xep = arr_lines[i].xep;
				tmpLines[i].ysp = arr_lines[i].ysp;
				tmpLines[i].yep = arr_lines[i].yep;
			}
			LSpeed->Text = "Speed: ";

			randomized = true;
		}

		// This method is used in the implementation for the sorting algorithms. This will swap two elements in the array and graphically display it on the pannel
		void swap(lines arr_lines[], int x, int y) {
			Pen^ blackPen = gcnew Pen(Color::Black);
			Pen^ whitePen = gcnew Pen(Color::White);
			Pen^ redPen = gcnew Pen(Color::Red);
			Pen^ greenPen = gcnew Pen(Color::Green);
			Point startPoint;
			Point endPoint;
			int yStart = 0;
			int yEnd = 0;
			
			startPoint.X = arr_lines[x].xsp;
			endPoint.X = arr_lines[x].xep;
			startPoint.Y = 280;
			endPoint.Y = 0;
			Sleep(sleepTime);
			g->DrawLine(blackPen, startPoint, endPoint);

			startPoint.X = arr_lines[y].xsp;
			endPoint.X = arr_lines[y].xep;
			startPoint.Y = 280;
			endPoint.Y = 0;
			Sleep(sleepTime);
			g->DrawLine(blackPen, startPoint, endPoint);

			yStart = arr_lines[y].ysp;
			yEnd = arr_lines[y].yep;
			arr_lines[y].ysp = arr_lines[x].ysp;
			arr_lines[y].yep = arr_lines[x].yep;
			arr_lines[x].ysp = yStart;
			arr_lines[x].yep = yEnd;

			startPoint.X = arr_lines[x].xsp;
			endPoint.X = arr_lines[x].xep;
			startPoint.Y = arr_lines[x].ysp;
			endPoint.Y = arr_lines[x].yep;
			Sleep(sleepTime);
			g->DrawLine(whitePen, startPoint, endPoint);


			startPoint.X = arr_lines[y].xsp;
			endPoint.X = arr_lines[y].xep;
			startPoint.Y = arr_lines[y].ysp;
			endPoint.Y = arr_lines[y].yep;
			Sleep(sleepTime);
			g->DrawLine(whitePen, startPoint, endPoint);
		}

		// This is used in the sorting algorithm implementations if you only need to change one of the variables
		void changeYEP(lines arr_lines[], int index, int yep) {
			Pen^ blackPen = gcnew Pen(Color::Black);
			Pen^ whitePen = gcnew Pen(Color::White);
			Point startPoint;
			Point endPoint;

			startPoint.X = arr_lines[index].xsp;
			endPoint.X = arr_lines[index].xep;
			startPoint.Y = 280;
			endPoint.Y = 0;
			Sleep(sleepTime);
			g->DrawLine(blackPen, startPoint, endPoint);

			endPoint.Y = yep;
			Sleep(sleepTime);
			g->DrawLine(whitePen, startPoint, endPoint);
		}

		void MyQuicksort(lines arr_lines[], int start, int end) {
			if (start < end) {
				int p = Partition(arr_lines, start, end);

				MyQuicksort(arr_lines, start, p - 1);
				MyQuicksort(arr_lines, p + 1, end);
			}
		}

		int Partition(lines arr_lines[], int start, int end) {
			Pen^ blackPen = gcnew Pen(Color::Black);
			Pen^ whitePen = gcnew Pen(Color::White);
			Pen^ redPen = gcnew Pen(Color::Red);
			Pen^ greenPen = gcnew Pen(Color::Green);

			int pivot = (280 - arr_lines[end].yep);

			int i = start - 1;
			for (int j = start; j < end; j++) {
				if ((280 - arr_lines[j].yep) <= pivot) {
					i++;
					swap(arr_lines, i, j);
				}
			}
			swap(arr_lines, i + 1, end);
			return(i + 1);
		}

		void Mergesort(lines arr_lines[], int start, int end) {
			if (start < end) {
				int middle = (start + end) / 2;
				Mergesort(arr_lines, start, middle);
				Mergesort(arr_lines, middle + 1, end);
				Merge(arr_lines, start, middle, end);
			}
		}


		void Merge(lines arr_lines[], int start, int middle, int end) {
			lines temp_lines[numElem];
			for (int i = 0; i < numElem; i++) {
				temp_lines[i].xsp = arr_lines[i].xsp;
				temp_lines[i].xep = arr_lines[i].xep;
				temp_lines[i].ysp = arr_lines[i].ysp;
				temp_lines[i].yep = arr_lines[i].yep;
			}

			int i = start;
			int j = middle + 1;
			int z = start;
			while (i <= middle && j <= end){
				if (280 - temp_lines[i].yep <= 280 - temp_lines[j].yep) {
					arr_lines[z].ysp = temp_lines[i].ysp;
					arr_lines[z].yep = temp_lines[i].yep;
					changeYEP(arr_lines, z, arr_lines[z].yep);
					i++;
				}
				else {
					arr_lines[z].ysp = temp_lines[j].ysp;
					arr_lines[z].yep = temp_lines[j].yep;
					changeYEP(arr_lines, z, arr_lines[z].yep);
					j++;
				}
				z++;
			}
			if (j > end) {
				int d = i;
				for (int y = z; y <= end; y++) {
					arr_lines[y].yep = temp_lines[d].yep;
					changeYEP(arr_lines, y, arr_lines[y].yep);
					d++;
				}
			}
			else if (i > middle) {
				for (int y = z; y <= end; y++) {
					arr_lines[y].yep = temp_lines[j].yep;
					changeYEP(arr_lines, y, arr_lines[y].yep);
					j++;
				}
			}
		}

		void insertionSort(lines arr_lines[], int numElements) {
			int i, key, j;

			for (i = 1; i < numElements; i++) {
				key = arr_lines[i].yep;
				j = i - 1;

				while ((j >= 0) && arr_lines[j].yep < key) {
					arr_lines[j + 1].yep = arr_lines[j].yep;
					changeYEP(arr_lines, (j + 1), arr_lines[j + 1].yep);
					j = j - 1;
				}
				arr_lines[j + 1].yep = key;
				changeYEP(arr_lines, (j + 1), arr_lines[j + 1].yep);
			}
		}

		void bubbleSort(lines arr_lines[], int numElements) {
			int i, j;
			bool swapped;
			for (i = 0; i < numElements - 1; i++) {
				swapped = false;
				for (j = 0; j < numElements - i - 1; j++) {
					if (280 - arr_lines[j].yep > 280 - arr_lines[j + 1].yep) {
						swap(arr_lines, j, j + 1);
						swapped = true;
					}
				}
				if (swapped == false) {
					break;
				}
			}
		}

		void selectionSort(lines arr_lines[], int numElements) {
			int i, j, min_index;

			for (i = 0; i < numElements - 1; i++) {
				min_index = i;
				for (j = i + 1; j < numElements; j++) {
					if (280 - arr_lines[j].yep < 280 - arr_lines[min_index].yep) {
						min_index = j;
					}
				}
				if (min_index != i) {
					swap(arr_lines, i, min_index);
				}
			}
		}

		// This method is used to blacken the entire problem, used in the randomize button
		void BlackenPanel() {
			Pen^ redPen = gcnew Pen(Color::Red);
			Pen^ blackPen = gcnew Pen(Color::Black);

			Point startPoint;
			Point endPoint;

			// Fill in Array
			for (int i = 0; i < numElem; i++) {
				startPoint.X = arr_lines[i].xsp;
				endPoint.X = arr_lines[i].xep;
				startPoint.Y = 280;
				endPoint.Y = 0;
				g->DrawLine(blackPen, startPoint, endPoint);  // Draw lines
			}
		};

		private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
		}
	};  // end of MyForm
}  // end GUIDataAlgorithmPersonalProject