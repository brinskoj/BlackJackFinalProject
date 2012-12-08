/**********************************************************************
***********************************************************************
***********************************************************************
***																	***
***						ID INFORMATION								***
***                                                        			***
***   Programmers				:			Johnny Brinsko		 	***
***   Assignment #				:   		Final Project	   		***
***   Assignment Name			:			BlackJack				***
***   Course # and Title		:	   		CISC 192 - C++			***
***   Class Meeting Time		:	   		TTh 9:35 - 12:40		***
***   Instructor				:			Professor Forman		***
***   Hours						:			29						***
***   Difficulty				:			8						***
***   Completion Date			:			12/13/2012				***
***   Project Name				:  			JohnnysBlackJack		***
***																	***
***********************************************************************
***********************************************************************
***                                       							***
***						PROGRAM DESCRIPTION              			***
***																	***
***	 User logs in with account number and password. Only 6 possible	***
***	 account numbers are valid. All share the same password, while	***
***	 only two passwords are valid. The password "blackjack" sets up	***
***	 the deck and shuffles it before the user presses Deal to begin	***
***	 playing. The password "master" enables a Show/Hide Test		***
***	 Buttons button. These test buttons allow the user to set up	***
***	 the deck, display the deck, shuffle the deck (2 different		***
***	 ways), deal a card, deal a hand, add a card to hand, arrange	***
***	 the hand from lowest to highest, store the current deck to		***
***	 disk, and load the current deck from the disk.	Play begins		***
***	 when player presses Deal button. Player has the option to hit	***
***	 or stand. A hit gives the player one more card only and a card	***
***	 for the dealer immediately after. A stand will just give one	***
***	 card to the dealer. The cards are evaluated after the fourth	***
***	 card is dealt and again after the last card is dealt. The game	***
***	 results are shown at the bottom. There is a game counter, win	***
***	 counter for player and dealer, and stats for both player and	***
***	 dealer. There is a Cheat button that provides several			***
***	 scenarios via a combo box. The Instruction button brings up	***
***	 a message box and provides instructions for the game. The 		***
***	 Results button displays the wins for both player and dealer in ***
***	 a message box. The Credits button shows ID info, media used,   ***
***	 and stars earned. The History button displays a history of all	***
***	 games played along with other cool game stats such as total	***
***	 hand values after each game for the player and which game was	***
***	 the lowest hand. When the user clicks the Exit button, the     ***
***	 player	is shown a farewell message with his and the dealer's 	***
***	 wins, and the message is tailored based on whether the player 	***
***	 accrued more wins than the dealer or not. Then the player is	***
***	 asked if he wants to play one more game. If not, the program	***
***	 closes.														***
***                                                         		***
***********************************************************************
***********************************************************************
***																	***
***					Event-Defined Function List						***
***                                                         		***
***		buttonAddACard_Click										***
***		buttonArrangeTheHand_Click									***
***		buttonCheat_Click											***
***		buttonCredits_Click											***
***		buttonDateTime_Click										***
***		buttonDeal_Click											***
***		buttonDealACard_Click										***
***		buttonDealAHand_Click										***
***		buttonDisplayDeck_Click										***
***		buttonExit_Click											***
***		buttonHistory_Click											***
***		buttonHit_Click												***
***		buttonInstructions_Click									***
***		buttonLoadDeck_Click										***
***		buttonLogin_Click											***
***		buttonResults_Click											***
***		buttonSetUpDeck_Click										***
***		buttonShuffleDeck_Click										***
***		buttonShuffleDeckPerfect_Click								***
***		buttonStay_Click											***
***		buttonStoreDeck_Click										***
***		buttonSubmit_Click											***
***		buttonTestFunctions_Click									***
***		Form1_Load													***
***																	***
***********************************************************************
***********************************************************************
***																	***
***					Custom-Defined Function List					***
***                                                         		***
***		addACardToHand												***
***		arrangeTheHand												***
***		cheatWithCard												***
***		check21														***
***		dealCard													***
***		dealACard													***
***		dealAHand													***
***		displayDateTime												***
***		displayDeck													***
***		isMaster													***
***		isValidPassword												***
***		loadDeck													***
***		setUpDeckByValue											***
***		shuffleDeck													***
***		shuffleDeckPerfect											***
***		storeDeck													***
***		updateHistory												***
***		verifyAccount												***
***																	***
***********************************************************************
***********************************************************************
***																	***
***                         CREDITS				                    ***
***                                                         		***
***   		Thanks for assistance and inspiration from:        		***
***                                                         		***
***			Professor Forman, Tim, Jeramy, Mowlana, Matt			***
***                                                         		***
***   		Thanks for the opportunity to assist and inspire:     	***
***								                               		***
***			Professor Forman, Tim, Jeramy, Mowlana, Matt			***
***                                                         		***
***********************************************************************
***********************************************************************
***																	***
***						      MEDIA				                    ***
***																	***
***		Background music during game:								***
***		http://www.youtube.com/watch?v=Y6ljFaKRTrI					***
***																	***
***		Farewell music:												***
***		http://www.gamefront.com/files/12899141/Portal_Radio_Loop	***
***																	***
***		Jose's cards from class, provided by Professor Forman		***
***																	***
***		Animated gif of blackjack dealing							***
***			(used gifsoup.com to convert video to gif)				***
***		http://www.youtube.com/watch?v=V6WQrbauJEQ					***
***																	***
***		Background image:											***
***	http://www.customtablefelt.com/images/suited-poker-felt/suited-poker-table-felt-400x300.jpg
***																	***
***********************************************************************
***********************************************************************
**********************************************************************/

#pragma once

#include <ctime>	// For the time() function
#include <iostream> // For srand() and rand()

namespace JohnnysBlackJack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO; // For file streaming

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			dateTimeStart = DateTime::Now;
			displayDateTime();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelWelcome;
	protected: 
	private: System::Windows::Forms::Label^  labelDateTime;
	private: System::Windows::Forms::Button^  buttonDateTime;
	private: System::Windows::Forms::PictureBox^  pictureBoxBJGif;
	private: System::Windows::Forms::Button^  buttonInstructions;
	private: System::Windows::Forms::Button^  buttonLogin;
	private: System::Windows::Forms::Button^  buttonExit;
	private: System::Windows::Forms::Button^  buttonCredits;
	private: System::Windows::Forms::Label^  labelEnterAccount;
	private: System::Windows::Forms::TextBox^  textBoxAccount;



	private: System::Windows::Forms::Button^  buttonSubmit;
	private: System::Windows::Forms::Button^  buttonResults;
	private: System::Windows::Forms::ImageList^  imageListCards;
	private: System::Windows::Forms::PictureBox^  pictureBoxPlayerCard1;
	private: System::Windows::Forms::PictureBox^  pictureBoxPlayerCard2;
	private: System::Windows::Forms::PictureBox^  pictureBoxPlayerCard3;
	private: System::Windows::Forms::PictureBox^  pictureBoxDealerCard1;
	private: System::Windows::Forms::PictureBox^  pictureBoxDealerCard2;
	private: System::Windows::Forms::PictureBox^  pictureBoxDealerCard3;
	private: System::Windows::Forms::Label^  labelPlayerCardValue1;
	private: System::Windows::Forms::Label^  labelPlayerCardValue2;
	private: System::Windows::Forms::Label^  labelPlayerCardValue3;
	private: System::Windows::Forms::Label^  labelDealerCardValue1;
	private: System::Windows::Forms::Label^  labelDealerCardValue2;
	private: System::Windows::Forms::Label^  labelDealerCardValue3;
	private: System::Windows::Forms::Button^  buttonDeal;
	private: System::Windows::Forms::Button^  buttonHit;
	private: System::Windows::Forms::Button^  buttonStay;
	private: System::Windows::Forms::Label^  labelPlayerObservation;
	private: System::Windows::Forms::Label^  labelDealerObservation;
	private: System::Windows::Forms::Label^  labelDealerAction;
	private: System::Windows::Forms::Label^  labelGameNumber;
	private: System::Windows::Forms::ComboBox^  comboBoxCheat;
	private: System::Windows::Forms::Button^  buttonCheat;
	private: System::Windows::Forms::Label^  labelSelectCheat;
	private: System::Windows::Forms::Label^  labelPlayerStats;
	private: System::Windows::Forms::Label^  labelDealerStats;
	private: System::Windows::Forms::Label^  labelEnterPassword;
	private: System::Windows::Forms::TextBox^  textBoxPassword;
	private: System::Windows::Forms::Button^  buttonSetUpDeck;
	private: System::Windows::Forms::Button^  buttonTestFunctions;
	private: System::Windows::Forms::Button^  buttonDisplayDeck;
	private: System::Windows::Forms::Button^  buttonShuffleDeck;
	private: System::Windows::Forms::Button^  buttonDealACard;
	private: System::Windows::Forms::Button^  buttonDealAHand;
	private: System::Windows::Forms::Button^  buttonAddACard;
	private: System::Windows::Forms::Button^  buttonArrangeTheHand;
	private: System::Windows::Forms::Button^  buttonStoreDeck;
	private: System::Windows::Forms::Button^  buttonLoadDeck;
	private: System::Windows::Forms::Button^  buttonReturn;
	private: System::Windows::Forms::Button^  buttonShuffleDeckPerfect;
	private: System::Windows::Forms::Button^  buttonHistory;






	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		value class CardType
		{
			public:
				int		cardValue;
				String^	cardName;
				String^ cardSuit;
				int		cardImageIndex;
		};

		value class GameHistory
		{
			public:
				int		histGameNumber;
				int		histHandTotal;
				String^	histWinOrLose;
		};


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->labelWelcome = (gcnew System::Windows::Forms::Label());
			this->labelDateTime = (gcnew System::Windows::Forms::Label());
			this->buttonDateTime = (gcnew System::Windows::Forms::Button());
			this->pictureBoxBJGif = (gcnew System::Windows::Forms::PictureBox());
			this->buttonInstructions = (gcnew System::Windows::Forms::Button());
			this->buttonLogin = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->buttonCredits = (gcnew System::Windows::Forms::Button());
			this->labelEnterAccount = (gcnew System::Windows::Forms::Label());
			this->textBoxAccount = (gcnew System::Windows::Forms::TextBox());
			this->buttonSubmit = (gcnew System::Windows::Forms::Button());
			this->buttonResults = (gcnew System::Windows::Forms::Button());
			this->imageListCards = (gcnew System::Windows::Forms::ImageList(this->components));
			this->pictureBoxPlayerCard1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxPlayerCard2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxPlayerCard3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDealerCard1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDealerCard2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDealerCard3 = (gcnew System::Windows::Forms::PictureBox());
			this->labelPlayerCardValue1 = (gcnew System::Windows::Forms::Label());
			this->labelPlayerCardValue2 = (gcnew System::Windows::Forms::Label());
			this->labelPlayerCardValue3 = (gcnew System::Windows::Forms::Label());
			this->labelDealerCardValue1 = (gcnew System::Windows::Forms::Label());
			this->labelDealerCardValue2 = (gcnew System::Windows::Forms::Label());
			this->labelDealerCardValue3 = (gcnew System::Windows::Forms::Label());
			this->buttonDeal = (gcnew System::Windows::Forms::Button());
			this->buttonHit = (gcnew System::Windows::Forms::Button());
			this->buttonStay = (gcnew System::Windows::Forms::Button());
			this->labelPlayerObservation = (gcnew System::Windows::Forms::Label());
			this->labelDealerObservation = (gcnew System::Windows::Forms::Label());
			this->labelDealerAction = (gcnew System::Windows::Forms::Label());
			this->labelGameNumber = (gcnew System::Windows::Forms::Label());
			this->comboBoxCheat = (gcnew System::Windows::Forms::ComboBox());
			this->buttonCheat = (gcnew System::Windows::Forms::Button());
			this->labelSelectCheat = (gcnew System::Windows::Forms::Label());
			this->labelPlayerStats = (gcnew System::Windows::Forms::Label());
			this->labelDealerStats = (gcnew System::Windows::Forms::Label());
			this->labelEnterPassword = (gcnew System::Windows::Forms::Label());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->buttonSetUpDeck = (gcnew System::Windows::Forms::Button());
			this->buttonTestFunctions = (gcnew System::Windows::Forms::Button());
			this->buttonDisplayDeck = (gcnew System::Windows::Forms::Button());
			this->buttonShuffleDeck = (gcnew System::Windows::Forms::Button());
			this->buttonDealACard = (gcnew System::Windows::Forms::Button());
			this->buttonDealAHand = (gcnew System::Windows::Forms::Button());
			this->buttonAddACard = (gcnew System::Windows::Forms::Button());
			this->buttonArrangeTheHand = (gcnew System::Windows::Forms::Button());
			this->buttonStoreDeck = (gcnew System::Windows::Forms::Button());
			this->buttonLoadDeck = (gcnew System::Windows::Forms::Button());
			this->buttonReturn = (gcnew System::Windows::Forms::Button());
			this->buttonShuffleDeckPerfect = (gcnew System::Windows::Forms::Button());
			this->buttonHistory = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxBJGif))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxPlayerCard1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxPlayerCard2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxPlayerCard3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxDealerCard1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxDealerCard2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxDealerCard3))->BeginInit();
			this->SuspendLayout();
			// 
			// labelWelcome
			// 
			this->labelWelcome->BackColor = System::Drawing::Color::Transparent;
			this->labelWelcome->Font = (gcnew System::Drawing::Font(L"Stencil", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelWelcome->ForeColor = System::Drawing::Color::Yellow;
			this->labelWelcome->Location = System::Drawing::Point(215, 18);
			this->labelWelcome->Name = L"labelWelcome";
			this->labelWelcome->Size = System::Drawing::Size(824, 81);
			this->labelWelcome->TabIndex = 0;
			this->labelWelcome->Text = L"Welcome to Johnny\'s Black Jack Parlor";
			this->labelWelcome->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelDateTime
			// 
			this->labelDateTime->AutoSize = true;
			this->labelDateTime->BackColor = System::Drawing::Color::Transparent;
			this->labelDateTime->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelDateTime->ForeColor = System::Drawing::Color::Yellow;
			this->labelDateTime->Location = System::Drawing::Point(13, 13);
			this->labelDateTime->Name = L"labelDateTime";
			this->labelDateTime->Size = System::Drawing::Size(198, 24);
			this->labelDateTime->TabIndex = 1;
			this->labelDateTime->Text = L"01/01/70  12:00:00 AM";
			// 
			// buttonDateTime
			// 
			this->buttonDateTime->BackColor = System::Drawing::Color::Yellow;
			this->buttonDateTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonDateTime->Location = System::Drawing::Point(17, 40);
			this->buttonDateTime->Name = L"buttonDateTime";
			this->buttonDateTime->Size = System::Drawing::Size(198, 30);
			this->buttonDateTime->TabIndex = 2;
			this->buttonDateTime->Text = L"Update Date and Time";
			this->buttonDateTime->UseVisualStyleBackColor = false;
			this->buttonDateTime->Click += gcnew System::EventHandler(this, &Form1::buttonDateTime_Click);
			// 
			// pictureBoxBJGif
			// 
			this->pictureBoxBJGif->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBoxBJGif.Image")));
			this->pictureBoxBJGif->Location = System::Drawing::Point(466, 124);
			this->pictureBoxBJGif->Name = L"pictureBoxBJGif";
			this->pictureBoxBJGif->Size = System::Drawing::Size(320, 180);
			this->pictureBoxBJGif->TabIndex = 3;
			this->pictureBoxBJGif->TabStop = false;
			// 
			// buttonInstructions
			// 
			this->buttonInstructions->BackColor = System::Drawing::Color::Yellow;
			this->buttonInstructions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonInstructions->Location = System::Drawing::Point(12, 502);
			this->buttonInstructions->Name = L"buttonInstructions";
			this->buttonInstructions->Size = System::Drawing::Size(150, 50);
			this->buttonInstructions->TabIndex = 4;
			this->buttonInstructions->Text = L"Instructions";
			this->buttonInstructions->UseVisualStyleBackColor = false;
			this->buttonInstructions->Click += gcnew System::EventHandler(this, &Form1::buttonInstructions_Click);
			// 
			// buttonLogin
			// 
			this->buttonLogin->BackColor = System::Drawing::Color::Yellow;
			this->buttonLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonLogin->Location = System::Drawing::Point(536, 500);
			this->buttonLogin->Name = L"buttonLogin";
			this->buttonLogin->Size = System::Drawing::Size(200, 50);
			this->buttonLogin->TabIndex = 5;
			this->buttonLogin->Text = L"Login";
			this->buttonLogin->UseVisualStyleBackColor = false;
			this->buttonLogin->Click += gcnew System::EventHandler(this, &Form1::buttonLogin_Click);
			// 
			// buttonExit
			// 
			this->buttonExit->BackColor = System::Drawing::Color::Yellow;
			this->buttonExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonExit->Location = System::Drawing::Point(1103, 502);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(149, 50);
			this->buttonExit->TabIndex = 6;
			this->buttonExit->Text = L"Exit";
			this->buttonExit->UseVisualStyleBackColor = false;
			this->buttonExit->Click += gcnew System::EventHandler(this, &Form1::buttonExit_Click);
			// 
			// buttonCredits
			// 
			this->buttonCredits->BackColor = System::Drawing::Color::Yellow;
			this->buttonCredits->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonCredits->Location = System::Drawing::Point(1103, 446);
			this->buttonCredits->Name = L"buttonCredits";
			this->buttonCredits->Size = System::Drawing::Size(149, 50);
			this->buttonCredits->TabIndex = 7;
			this->buttonCredits->Text = L"Credits";
			this->buttonCredits->UseVisualStyleBackColor = false;
			this->buttonCredits->Click += gcnew System::EventHandler(this, &Form1::buttonCredits_Click);
			// 
			// labelEnterAccount
			// 
			this->labelEnterAccount->AutoSize = true;
			this->labelEnterAccount->BackColor = System::Drawing::Color::Transparent;
			this->labelEnterAccount->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelEnterAccount->ForeColor = System::Drawing::Color::Yellow;
			this->labelEnterAccount->Location = System::Drawing::Point(311, 327);
			this->labelEnterAccount->Name = L"labelEnterAccount";
			this->labelEnterAccount->Size = System::Drawing::Size(367, 29);
			this->labelEnterAccount->TabIndex = 8;
			this->labelEnterAccount->Text = L"Please enter your account number:";
			this->labelEnterAccount->Visible = false;
			// 
			// textBoxAccount
			// 
			this->textBoxAccount->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBoxAccount->Location = System::Drawing::Point(684, 323);
			this->textBoxAccount->Name = L"textBoxAccount";
			this->textBoxAccount->Size = System::Drawing::Size(195, 33);
			this->textBoxAccount->TabIndex = 9;
			this->textBoxAccount->Visible = false;
			// 
			// buttonSubmit
			// 
			this->buttonSubmit->BackColor = System::Drawing::Color::Yellow;
			this->buttonSubmit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonSubmit->Location = System::Drawing::Point(536, 444);
			this->buttonSubmit->Name = L"buttonSubmit";
			this->buttonSubmit->Size = System::Drawing::Size(200, 50);
			this->buttonSubmit->TabIndex = 11;
			this->buttonSubmit->Text = L"Submit";
			this->buttonSubmit->UseVisualStyleBackColor = false;
			this->buttonSubmit->Visible = false;
			this->buttonSubmit->Click += gcnew System::EventHandler(this, &Form1::buttonSubmit_Click);
			// 
			// buttonResults
			// 
			this->buttonResults->BackColor = System::Drawing::Color::Yellow;
			this->buttonResults->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonResults->Location = System::Drawing::Point(11, 446);
			this->buttonResults->Name = L"buttonResults";
			this->buttonResults->Size = System::Drawing::Size(150, 50);
			this->buttonResults->TabIndex = 12;
			this->buttonResults->Text = L"Results";
			this->buttonResults->UseVisualStyleBackColor = false;
			this->buttonResults->Visible = false;
			this->buttonResults->Click += gcnew System::EventHandler(this, &Form1::buttonResults_Click);
			// 
			// imageListCards
			// 
			this->imageListCards->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^  >(resources->GetObject(L"imageListCards.ImageStream")));
			this->imageListCards->TransparentColor = System::Drawing::Color::Transparent;
			this->imageListCards->Images->SetKeyName(0, L"2c.gif");
			this->imageListCards->Images->SetKeyName(1, L"2d.gif");
			this->imageListCards->Images->SetKeyName(2, L"2h.gif");
			this->imageListCards->Images->SetKeyName(3, L"2s.gif");
			this->imageListCards->Images->SetKeyName(4, L"3c.gif");
			this->imageListCards->Images->SetKeyName(5, L"3d.gif");
			this->imageListCards->Images->SetKeyName(6, L"3h.gif");
			this->imageListCards->Images->SetKeyName(7, L"3s.gif");
			this->imageListCards->Images->SetKeyName(8, L"4c.gif");
			this->imageListCards->Images->SetKeyName(9, L"4d.gif");
			this->imageListCards->Images->SetKeyName(10, L"4h.gif");
			this->imageListCards->Images->SetKeyName(11, L"4s.gif");
			this->imageListCards->Images->SetKeyName(12, L"5c.gif");
			this->imageListCards->Images->SetKeyName(13, L"5d.gif");
			this->imageListCards->Images->SetKeyName(14, L"5h.gif");
			this->imageListCards->Images->SetKeyName(15, L"5s.gif");
			this->imageListCards->Images->SetKeyName(16, L"6c.gif");
			this->imageListCards->Images->SetKeyName(17, L"6d.gif");
			this->imageListCards->Images->SetKeyName(18, L"6h.gif");
			this->imageListCards->Images->SetKeyName(19, L"6s.gif");
			this->imageListCards->Images->SetKeyName(20, L"7c.gif");
			this->imageListCards->Images->SetKeyName(21, L"7d.gif");
			this->imageListCards->Images->SetKeyName(22, L"7h.gif");
			this->imageListCards->Images->SetKeyName(23, L"7s.gif");
			this->imageListCards->Images->SetKeyName(24, L"8c.gif");
			this->imageListCards->Images->SetKeyName(25, L"8d.gif");
			this->imageListCards->Images->SetKeyName(26, L"8h.gif");
			this->imageListCards->Images->SetKeyName(27, L"8s.gif");
			this->imageListCards->Images->SetKeyName(28, L"9c.gif");
			this->imageListCards->Images->SetKeyName(29, L"9d.gif");
			this->imageListCards->Images->SetKeyName(30, L"9h.gif");
			this->imageListCards->Images->SetKeyName(31, L"9s.gif");
			this->imageListCards->Images->SetKeyName(32, L"tc.gif");
			this->imageListCards->Images->SetKeyName(33, L"td.gif");
			this->imageListCards->Images->SetKeyName(34, L"th.gif");
			this->imageListCards->Images->SetKeyName(35, L"ts.gif");
			this->imageListCards->Images->SetKeyName(36, L"jc.gif");
			this->imageListCards->Images->SetKeyName(37, L"jd.gif");
			this->imageListCards->Images->SetKeyName(38, L"jh.gif");
			this->imageListCards->Images->SetKeyName(39, L"js.gif");
			this->imageListCards->Images->SetKeyName(40, L"qc.gif");
			this->imageListCards->Images->SetKeyName(41, L"qd.gif");
			this->imageListCards->Images->SetKeyName(42, L"qh.gif");
			this->imageListCards->Images->SetKeyName(43, L"qs.gif");
			this->imageListCards->Images->SetKeyName(44, L"kc.gif");
			this->imageListCards->Images->SetKeyName(45, L"kd.gif");
			this->imageListCards->Images->SetKeyName(46, L"kh.gif");
			this->imageListCards->Images->SetKeyName(47, L"ks.gif");
			this->imageListCards->Images->SetKeyName(48, L"ac.gif");
			this->imageListCards->Images->SetKeyName(49, L"ad.gif");
			this->imageListCards->Images->SetKeyName(50, L"ah.gif");
			this->imageListCards->Images->SetKeyName(51, L"as.gif");
			// 
			// pictureBoxPlayerCard1
			// 
			this->pictureBoxPlayerCard1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxPlayerCard1->Location = System::Drawing::Point(17, 99);
			this->pictureBoxPlayerCard1->Name = L"pictureBoxPlayerCard1";
			this->pictureBoxPlayerCard1->Size = System::Drawing::Size(73, 97);
			this->pictureBoxPlayerCard1->TabIndex = 13;
			this->pictureBoxPlayerCard1->TabStop = false;
			// 
			// pictureBoxPlayerCard2
			// 
			this->pictureBoxPlayerCard2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxPlayerCard2->Location = System::Drawing::Point(17, 224);
			this->pictureBoxPlayerCard2->Name = L"pictureBoxPlayerCard2";
			this->pictureBoxPlayerCard2->Size = System::Drawing::Size(73, 97);
			this->pictureBoxPlayerCard2->TabIndex = 14;
			this->pictureBoxPlayerCard2->TabStop = false;
			// 
			// pictureBoxPlayerCard3
			// 
			this->pictureBoxPlayerCard3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxPlayerCard3->Location = System::Drawing::Point(20, 341);
			this->pictureBoxPlayerCard3->Name = L"pictureBoxPlayerCard3";
			this->pictureBoxPlayerCard3->Size = System::Drawing::Size(73, 97);
			this->pictureBoxPlayerCard3->TabIndex = 15;
			this->pictureBoxPlayerCard3->TabStop = false;
			// 
			// pictureBoxDealerCard1
			// 
			this->pictureBoxDealerCard1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxDealerCard1->Location = System::Drawing::Point(1164, 99);
			this->pictureBoxDealerCard1->Name = L"pictureBoxDealerCard1";
			this->pictureBoxDealerCard1->Size = System::Drawing::Size(73, 97);
			this->pictureBoxDealerCard1->TabIndex = 16;
			this->pictureBoxDealerCard1->TabStop = false;
			// 
			// pictureBoxDealerCard2
			// 
			this->pictureBoxDealerCard2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxDealerCard2->Location = System::Drawing::Point(1164, 224);
			this->pictureBoxDealerCard2->Name = L"pictureBoxDealerCard2";
			this->pictureBoxDealerCard2->Size = System::Drawing::Size(73, 97);
			this->pictureBoxDealerCard2->TabIndex = 17;
			this->pictureBoxDealerCard2->TabStop = false;
			// 
			// pictureBoxDealerCard3
			// 
			this->pictureBoxDealerCard3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxDealerCard3->Location = System::Drawing::Point(1164, 341);
			this->pictureBoxDealerCard3->Name = L"pictureBoxDealerCard3";
			this->pictureBoxDealerCard3->Size = System::Drawing::Size(73, 97);
			this->pictureBoxDealerCard3->TabIndex = 18;
			this->pictureBoxDealerCard3->TabStop = false;
			// 
			// labelPlayerCardValue1
			// 
			this->labelPlayerCardValue1->AutoSize = true;
			this->labelPlayerCardValue1->BackColor = System::Drawing::Color::Transparent;
			this->labelPlayerCardValue1->ForeColor = System::Drawing::Color::Yellow;
			this->labelPlayerCardValue1->Location = System::Drawing::Point(17, 80);
			this->labelPlayerCardValue1->Name = L"labelPlayerCardValue1";
			this->labelPlayerCardValue1->Size = System::Drawing::Size(65, 13);
			this->labelPlayerCardValue1->TabIndex = 19;
			this->labelPlayerCardValue1->Text = L"Card Value: ";
			this->labelPlayerCardValue1->Visible = false;
			// 
			// labelPlayerCardValue2
			// 
			this->labelPlayerCardValue2->AutoSize = true;
			this->labelPlayerCardValue2->BackColor = System::Drawing::Color::Transparent;
			this->labelPlayerCardValue2->ForeColor = System::Drawing::Color::Yellow;
			this->labelPlayerCardValue2->Location = System::Drawing::Point(17, 208);
			this->labelPlayerCardValue2->Name = L"labelPlayerCardValue2";
			this->labelPlayerCardValue2->Size = System::Drawing::Size(65, 13);
			this->labelPlayerCardValue2->TabIndex = 20;
			this->labelPlayerCardValue2->Text = L"Card Value: ";
			this->labelPlayerCardValue2->Visible = false;
			// 
			// labelPlayerCardValue3
			// 
			this->labelPlayerCardValue3->AutoSize = true;
			this->labelPlayerCardValue3->BackColor = System::Drawing::Color::Transparent;
			this->labelPlayerCardValue3->ForeColor = System::Drawing::Color::Yellow;
			this->labelPlayerCardValue3->Location = System::Drawing::Point(20, 325);
			this->labelPlayerCardValue3->Name = L"labelPlayerCardValue3";
			this->labelPlayerCardValue3->Size = System::Drawing::Size(65, 13);
			this->labelPlayerCardValue3->TabIndex = 21;
			this->labelPlayerCardValue3->Text = L"Card Value: ";
			this->labelPlayerCardValue3->Visible = false;
			// 
			// labelDealerCardValue1
			// 
			this->labelDealerCardValue1->AutoSize = true;
			this->labelDealerCardValue1->BackColor = System::Drawing::Color::Transparent;
			this->labelDealerCardValue1->ForeColor = System::Drawing::Color::Yellow;
			this->labelDealerCardValue1->Location = System::Drawing::Point(1161, 80);
			this->labelDealerCardValue1->Name = L"labelDealerCardValue1";
			this->labelDealerCardValue1->Size = System::Drawing::Size(65, 13);
			this->labelDealerCardValue1->TabIndex = 22;
			this->labelDealerCardValue1->Text = L"Card Value: ";
			this->labelDealerCardValue1->Visible = false;
			// 
			// labelDealerCardValue2
			// 
			this->labelDealerCardValue2->AutoSize = true;
			this->labelDealerCardValue2->BackColor = System::Drawing::Color::Transparent;
			this->labelDealerCardValue2->ForeColor = System::Drawing::Color::Yellow;
			this->labelDealerCardValue2->Location = System::Drawing::Point(1161, 205);
			this->labelDealerCardValue2->Name = L"labelDealerCardValue2";
			this->labelDealerCardValue2->Size = System::Drawing::Size(65, 13);
			this->labelDealerCardValue2->TabIndex = 23;
			this->labelDealerCardValue2->Text = L"Card Value: ";
			this->labelDealerCardValue2->Visible = false;
			// 
			// labelDealerCardValue3
			// 
			this->labelDealerCardValue3->AutoSize = true;
			this->labelDealerCardValue3->BackColor = System::Drawing::Color::Transparent;
			this->labelDealerCardValue3->ForeColor = System::Drawing::Color::Yellow;
			this->labelDealerCardValue3->Location = System::Drawing::Point(1161, 325);
			this->labelDealerCardValue3->Name = L"labelDealerCardValue3";
			this->labelDealerCardValue3->Size = System::Drawing::Size(65, 13);
			this->labelDealerCardValue3->TabIndex = 24;
			this->labelDealerCardValue3->Text = L"Card Value: ";
			this->labelDealerCardValue3->Visible = false;
			// 
			// buttonDeal
			// 
			this->buttonDeal->BackColor = System::Drawing::Color::Yellow;
			this->buttonDeal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonDeal->Location = System::Drawing::Point(468, 314);
			this->buttonDeal->Name = L"buttonDeal";
			this->buttonDeal->Size = System::Drawing::Size(73, 23);
			this->buttonDeal->TabIndex = 25;
			this->buttonDeal->Text = L"Deal";
			this->buttonDeal->UseVisualStyleBackColor = false;
			this->buttonDeal->Visible = false;
			this->buttonDeal->Click += gcnew System::EventHandler(this, &Form1::buttonDeal_Click);
			// 
			// buttonHit
			// 
			this->buttonHit->BackColor = System::Drawing::Color::Yellow;
			this->buttonHit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonHit->Location = System::Drawing::Point(549, 314);
			this->buttonHit->Name = L"buttonHit";
			this->buttonHit->Size = System::Drawing::Size(73, 23);
			this->buttonHit->TabIndex = 26;
			this->buttonHit->Text = L"Hit";
			this->buttonHit->UseVisualStyleBackColor = false;
			this->buttonHit->Visible = false;
			this->buttonHit->Click += gcnew System::EventHandler(this, &Form1::buttonHit_Click);
			// 
			// buttonStay
			// 
			this->buttonStay->BackColor = System::Drawing::Color::Yellow;
			this->buttonStay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonStay->Location = System::Drawing::Point(630, 314);
			this->buttonStay->Name = L"buttonStay";
			this->buttonStay->Size = System::Drawing::Size(73, 23);
			this->buttonStay->TabIndex = 27;
			this->buttonStay->Text = L"Stay";
			this->buttonStay->UseVisualStyleBackColor = false;
			this->buttonStay->Visible = false;
			this->buttonStay->Click += gcnew System::EventHandler(this, &Form1::buttonStay_Click);
			// 
			// labelPlayerObservation
			// 
			this->labelPlayerObservation->BackColor = System::Drawing::Color::Transparent;
			this->labelPlayerObservation->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelPlayerObservation->ForeColor = System::Drawing::Color::Yellow;
			this->labelPlayerObservation->Location = System::Drawing::Point(129, 99);
			this->labelPlayerObservation->Name = L"labelPlayerObservation";
			this->labelPlayerObservation->Size = System::Drawing::Size(320, 23);
			this->labelPlayerObservation->TabIndex = 28;
			this->labelPlayerObservation->Text = L"Player\'s hand value: ";
			this->labelPlayerObservation->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->labelPlayerObservation->Visible = false;
			// 
			// labelDealerObservation
			// 
			this->labelDealerObservation->BackColor = System::Drawing::Color::Transparent;
			this->labelDealerObservation->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelDealerObservation->ForeColor = System::Drawing::Color::Yellow;
			this->labelDealerObservation->Location = System::Drawing::Point(813, 99);
			this->labelDealerObservation->Name = L"labelDealerObservation";
			this->labelDealerObservation->Size = System::Drawing::Size(241, 23);
			this->labelDealerObservation->TabIndex = 29;
			this->labelDealerObservation->Text = L"Dealer\'s Hand Value: ";
			this->labelDealerObservation->Visible = false;
			// 
			// labelDealerAction
			// 
			this->labelDealerAction->BackColor = System::Drawing::Color::Transparent;
			this->labelDealerAction->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelDealerAction->ForeColor = System::Drawing::Color::Yellow;
			this->labelDealerAction->Location = System::Drawing::Point(254, 381);
			this->labelDealerAction->Name = L"labelDealerAction";
			this->labelDealerAction->Size = System::Drawing::Size(759, 106);
			this->labelDealerAction->TabIndex = 30;
			this->labelDealerAction->Visible = false;
			// 
			// labelGameNumber
			// 
			this->labelGameNumber->AutoSize = true;
			this->labelGameNumber->BackColor = System::Drawing::Color::Transparent;
			this->labelGameNumber->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelGameNumber->ForeColor = System::Drawing::Color::Yellow;
			this->labelGameNumber->Location = System::Drawing::Point(562, 356);
			this->labelGameNumber->Name = L"labelGameNumber";
			this->labelGameNumber->Size = System::Drawing::Size(80, 25);
			this->labelGameNumber->TabIndex = 31;
			this->labelGameNumber->Text = L"Game #";
			this->labelGameNumber->Visible = false;
			// 
			// comboBoxCheat
			// 
			this->comboBoxCheat->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(47)), static_cast<System::Int32>(static_cast<System::Byte>(111)), 
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->comboBoxCheat->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboBoxCheat->Font = (gcnew System::Drawing::Font(L"Candara", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->comboBoxCheat->ForeColor = System::Drawing::Color::Yellow;
			this->comboBoxCheat->FormattingEnabled = true;
			this->comboBoxCheat->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"Player gets BlackJack", L"Dealer gets BlackJack", 
				L"Both get BlackJack", L"Player Busts and Dealer under threshold", L"Player Busts and Dealer within threshold", L"Dealer Busts and Player does not", 
				L"Player has 10 and Dealer has 10", L"Player has 10 and Dealer has 15", L"Player has 10 and Dealer has 16", L"Player has 20 and Dealer has 10", 
				L"Player has 20 and Dealer has 15", L"Player has 20 and Dealer has 16"});
			this->comboBoxCheat->Location = System::Drawing::Point(709, 343);
			this->comboBoxCheat->Name = L"comboBoxCheat";
			this->comboBoxCheat->Size = System::Drawing::Size(304, 23);
			this->comboBoxCheat->TabIndex = 32;
			this->comboBoxCheat->Visible = false;
			// 
			// buttonCheat
			// 
			this->buttonCheat->BackColor = System::Drawing::Color::Yellow;
			this->buttonCheat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonCheat->Location = System::Drawing::Point(711, 314);
			this->buttonCheat->Name = L"buttonCheat";
			this->buttonCheat->Size = System::Drawing::Size(73, 23);
			this->buttonCheat->TabIndex = 33;
			this->buttonCheat->Text = L"Cheat";
			this->buttonCheat->UseVisualStyleBackColor = false;
			this->buttonCheat->Visible = false;
			this->buttonCheat->Click += gcnew System::EventHandler(this, &Form1::buttonCheat_Click);
			// 
			// labelSelectCheat
			// 
			this->labelSelectCheat->AutoSize = true;
			this->labelSelectCheat->BackColor = System::Drawing::Color::Transparent;
			this->labelSelectCheat->Font = (gcnew System::Drawing::Font(L"Candara", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelSelectCheat->ForeColor = System::Drawing::Color::Yellow;
			this->labelSelectCheat->Location = System::Drawing::Point(790, 319);
			this->labelSelectCheat->Name = L"labelSelectCheat";
			this->labelSelectCheat->Size = System::Drawing::Size(216, 18);
			this->labelSelectCheat->TabIndex = 34;
			this->labelSelectCheat->Text = L"Select condition and press CHEAT";
			this->labelSelectCheat->Visible = false;
			// 
			// labelPlayerStats
			// 
			this->labelPlayerStats->BackColor = System::Drawing::Color::Transparent;
			this->labelPlayerStats->Font = (gcnew System::Drawing::Font(L"Candara", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelPlayerStats->ForeColor = System::Drawing::Color::Yellow;
			this->labelPlayerStats->Location = System::Drawing::Point(202, 150);
			this->labelPlayerStats->Name = L"labelPlayerStats";
			this->labelPlayerStats->Size = System::Drawing::Size(258, 154);
			this->labelPlayerStats->TabIndex = 35;
			this->labelPlayerStats->Text = L"Wins: \r\n\r\nLosses: ";
			this->labelPlayerStats->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->labelPlayerStats->Visible = false;
			// 
			// labelDealerStats
			// 
			this->labelDealerStats->BackColor = System::Drawing::Color::Transparent;
			this->labelDealerStats->Font = (gcnew System::Drawing::Font(L"Candara", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelDealerStats->ForeColor = System::Drawing::Color::Yellow;
			this->labelDealerStats->Location = System::Drawing::Point(814, 150);
			this->labelDealerStats->Name = L"labelDealerStats";
			this->labelDealerStats->Size = System::Drawing::Size(267, 154);
			this->labelDealerStats->TabIndex = 36;
			this->labelDealerStats->Text = L"Wins: \r\n\r\nLosses: ";
			this->labelDealerStats->Visible = false;
			// 
			// labelEnterPassword
			// 
			this->labelEnterPassword->AutoSize = true;
			this->labelEnterPassword->BackColor = System::Drawing::Color::Transparent;
			this->labelEnterPassword->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelEnterPassword->ForeColor = System::Drawing::Color::Yellow;
			this->labelEnterPassword->Location = System::Drawing::Point(311, 378);
			this->labelEnterPassword->Name = L"labelEnterPassword";
			this->labelEnterPassword->Size = System::Drawing::Size(298, 29);
			this->labelEnterPassword->TabIndex = 37;
			this->labelEnterPassword->Text = L"Please enter your password:";
			this->labelEnterPassword->Visible = false;
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBoxPassword->Location = System::Drawing::Point(684, 374);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->PasswordChar = '*';
			this->textBoxPassword->Size = System::Drawing::Size(195, 33);
			this->textBoxPassword->TabIndex = 38;
			this->textBoxPassword->Visible = false;
			// 
			// buttonSetUpDeck
			// 
			this->buttonSetUpDeck->BackColor = System::Drawing::Color::Yellow;
			this->buttonSetUpDeck->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonSetUpDeck->Location = System::Drawing::Point(167, 446);
			this->buttonSetUpDeck->Name = L"buttonSetUpDeck";
			this->buttonSetUpDeck->Size = System::Drawing::Size(150, 50);
			this->buttonSetUpDeck->TabIndex = 39;
			this->buttonSetUpDeck->Text = L"Set Up Deck";
			this->buttonSetUpDeck->UseVisualStyleBackColor = false;
			this->buttonSetUpDeck->Visible = false;
			this->buttonSetUpDeck->Click += gcnew System::EventHandler(this, &Form1::buttonSetUpDeck_Click);
			// 
			// buttonTestFunctions
			// 
			this->buttonTestFunctions->BackColor = System::Drawing::Color::Yellow;
			this->buttonTestFunctions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonTestFunctions->Location = System::Drawing::Point(1052, 40);
			this->buttonTestFunctions->Name = L"buttonTestFunctions";
			this->buttonTestFunctions->Size = System::Drawing::Size(198, 30);
			this->buttonTestFunctions->TabIndex = 40;
			this->buttonTestFunctions->Text = L"Show Test Buttons";
			this->buttonTestFunctions->UseVisualStyleBackColor = false;
			this->buttonTestFunctions->Visible = false;
			this->buttonTestFunctions->Click += gcnew System::EventHandler(this, &Form1::buttonTestFunctions_Click);
			// 
			// buttonDisplayDeck
			// 
			this->buttonDisplayDeck->BackColor = System::Drawing::Color::Yellow;
			this->buttonDisplayDeck->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonDisplayDeck->Location = System::Drawing::Point(167, 502);
			this->buttonDisplayDeck->Name = L"buttonDisplayDeck";
			this->buttonDisplayDeck->Size = System::Drawing::Size(150, 50);
			this->buttonDisplayDeck->TabIndex = 41;
			this->buttonDisplayDeck->Text = L"Display Deck";
			this->buttonDisplayDeck->UseVisualStyleBackColor = false;
			this->buttonDisplayDeck->Visible = false;
			this->buttonDisplayDeck->Click += gcnew System::EventHandler(this, &Form1::buttonDisplayDeck_Click);
			// 
			// buttonShuffleDeck
			// 
			this->buttonShuffleDeck->BackColor = System::Drawing::Color::Yellow;
			this->buttonShuffleDeck->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonShuffleDeck->Location = System::Drawing::Point(323, 446);
			this->buttonShuffleDeck->Name = L"buttonShuffleDeck";
			this->buttonShuffleDeck->Size = System::Drawing::Size(150, 50);
			this->buttonShuffleDeck->TabIndex = 42;
			this->buttonShuffleDeck->Text = L"Shuffle Deck";
			this->buttonShuffleDeck->UseVisualStyleBackColor = false;
			this->buttonShuffleDeck->Visible = false;
			this->buttonShuffleDeck->Click += gcnew System::EventHandler(this, &Form1::buttonShuffleDeck_Click);
			// 
			// buttonDealACard
			// 
			this->buttonDealACard->BackColor = System::Drawing::Color::Yellow;
			this->buttonDealACard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonDealACard->Location = System::Drawing::Point(323, 502);
			this->buttonDealACard->Name = L"buttonDealACard";
			this->buttonDealACard->Size = System::Drawing::Size(150, 50);
			this->buttonDealACard->TabIndex = 43;
			this->buttonDealACard->Text = L"Deal A Card";
			this->buttonDealACard->UseVisualStyleBackColor = false;
			this->buttonDealACard->Visible = false;
			this->buttonDealACard->Click += gcnew System::EventHandler(this, &Form1::buttonDealACard_Click);
			// 
			// buttonDealAHand
			// 
			this->buttonDealAHand->BackColor = System::Drawing::Color::Yellow;
			this->buttonDealAHand->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonDealAHand->Location = System::Drawing::Point(479, 502);
			this->buttonDealAHand->Name = L"buttonDealAHand";
			this->buttonDealAHand->Size = System::Drawing::Size(150, 50);
			this->buttonDealAHand->TabIndex = 44;
			this->buttonDealAHand->Text = L"Deal A Hand";
			this->buttonDealAHand->UseVisualStyleBackColor = false;
			this->buttonDealAHand->Visible = false;
			this->buttonDealAHand->Click += gcnew System::EventHandler(this, &Form1::buttonDealHand_Click);
			// 
			// buttonAddACard
			// 
			this->buttonAddACard->BackColor = System::Drawing::Color::Yellow;
			this->buttonAddACard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonAddACard->Location = System::Drawing::Point(635, 502);
			this->buttonAddACard->Name = L"buttonAddACard";
			this->buttonAddACard->Size = System::Drawing::Size(150, 50);
			this->buttonAddACard->TabIndex = 45;
			this->buttonAddACard->Text = L"Add A Card";
			this->buttonAddACard->UseVisualStyleBackColor = false;
			this->buttonAddACard->Visible = false;
			this->buttonAddACard->Click += gcnew System::EventHandler(this, &Form1::buttonAddACard_Click);
			// 
			// buttonArrangeTheHand
			// 
			this->buttonArrangeTheHand->BackColor = System::Drawing::Color::Yellow;
			this->buttonArrangeTheHand->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonArrangeTheHand->Location = System::Drawing::Point(635, 446);
			this->buttonArrangeTheHand->Name = L"buttonArrangeTheHand";
			this->buttonArrangeTheHand->Size = System::Drawing::Size(150, 50);
			this->buttonArrangeTheHand->TabIndex = 46;
			this->buttonArrangeTheHand->Text = L"Arrange the Hand";
			this->buttonArrangeTheHand->UseVisualStyleBackColor = false;
			this->buttonArrangeTheHand->Visible = false;
			this->buttonArrangeTheHand->Click += gcnew System::EventHandler(this, &Form1::buttonArrangeTheHand_Click);
			// 
			// buttonStoreDeck
			// 
			this->buttonStoreDeck->BackColor = System::Drawing::Color::Yellow;
			this->buttonStoreDeck->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonStoreDeck->Location = System::Drawing::Point(791, 446);
			this->buttonStoreDeck->Name = L"buttonStoreDeck";
			this->buttonStoreDeck->Size = System::Drawing::Size(150, 50);
			this->buttonStoreDeck->TabIndex = 47;
			this->buttonStoreDeck->Text = L"Store Deck to Disk";
			this->buttonStoreDeck->UseVisualStyleBackColor = false;
			this->buttonStoreDeck->Visible = false;
			this->buttonStoreDeck->Click += gcnew System::EventHandler(this, &Form1::buttonStoreDeck_Click);
			// 
			// buttonLoadDeck
			// 
			this->buttonLoadDeck->BackColor = System::Drawing::Color::Yellow;
			this->buttonLoadDeck->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonLoadDeck->Location = System::Drawing::Point(791, 502);
			this->buttonLoadDeck->Name = L"buttonLoadDeck";
			this->buttonLoadDeck->Size = System::Drawing::Size(150, 50);
			this->buttonLoadDeck->TabIndex = 48;
			this->buttonLoadDeck->Text = L"Load Deck from Disk";
			this->buttonLoadDeck->UseVisualStyleBackColor = false;
			this->buttonLoadDeck->Visible = false;
			this->buttonLoadDeck->Click += gcnew System::EventHandler(this, &Form1::buttonLoadDeck_Click);
			// 
			// buttonReturn
			// 
			this->buttonReturn->BackColor = System::Drawing::Color::Yellow;
			this->buttonReturn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonReturn->Location = System::Drawing::Point(947, 502);
			this->buttonReturn->Name = L"buttonReturn";
			this->buttonReturn->Size = System::Drawing::Size(150, 50);
			this->buttonReturn->TabIndex = 49;
			this->buttonReturn->Text = L"Return from Debug Mode";
			this->buttonReturn->UseVisualStyleBackColor = false;
			this->buttonReturn->Visible = false;
			this->buttonReturn->Click += gcnew System::EventHandler(this, &Form1::buttonReturn_Click);
			// 
			// buttonShuffleDeckPerfect
			// 
			this->buttonShuffleDeckPerfect->BackColor = System::Drawing::Color::Yellow;
			this->buttonShuffleDeckPerfect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonShuffleDeckPerfect->Location = System::Drawing::Point(479, 446);
			this->buttonShuffleDeckPerfect->Name = L"buttonShuffleDeckPerfect";
			this->buttonShuffleDeckPerfect->Size = System::Drawing::Size(150, 50);
			this->buttonShuffleDeckPerfect->TabIndex = 50;
			this->buttonShuffleDeckPerfect->Text = L"Shuffle Deck Perfect";
			this->buttonShuffleDeckPerfect->UseVisualStyleBackColor = false;
			this->buttonShuffleDeckPerfect->Visible = false;
			this->buttonShuffleDeckPerfect->Click += gcnew System::EventHandler(this, &Form1::buttonShuffleDeckPerfect_Click);
			// 
			// buttonHistory
			// 
			this->buttonHistory->BackColor = System::Drawing::Color::Yellow;
			this->buttonHistory->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonHistory->Location = System::Drawing::Point(947, 446);
			this->buttonHistory->Name = L"buttonHistory";
			this->buttonHistory->Size = System::Drawing::Size(150, 50);
			this->buttonHistory->TabIndex = 51;
			this->buttonHistory->Text = L"History";
			this->buttonHistory->UseVisualStyleBackColor = false;
			this->buttonHistory->Visible = false;
			this->buttonHistory->Click += gcnew System::EventHandler(this, &Form1::buttonHistory_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1264, 562);
			this->Controls->Add(this->buttonHistory);
			this->Controls->Add(this->buttonShuffleDeckPerfect);
			this->Controls->Add(this->buttonReturn);
			this->Controls->Add(this->buttonLoadDeck);
			this->Controls->Add(this->buttonStoreDeck);
			this->Controls->Add(this->buttonArrangeTheHand);
			this->Controls->Add(this->buttonAddACard);
			this->Controls->Add(this->buttonDealAHand);
			this->Controls->Add(this->buttonDealACard);
			this->Controls->Add(this->buttonShuffleDeck);
			this->Controls->Add(this->buttonDisplayDeck);
			this->Controls->Add(this->buttonTestFunctions);
			this->Controls->Add(this->buttonSetUpDeck);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->labelEnterPassword);
			this->Controls->Add(this->buttonSubmit);
			this->Controls->Add(this->buttonLogin);
			this->Controls->Add(this->labelDealerStats);
			this->Controls->Add(this->labelPlayerStats);
			this->Controls->Add(this->labelSelectCheat);
			this->Controls->Add(this->buttonCheat);
			this->Controls->Add(this->comboBoxCheat);
			this->Controls->Add(this->labelGameNumber);
			this->Controls->Add(this->labelDealerAction);
			this->Controls->Add(this->labelDealerObservation);
			this->Controls->Add(this->labelPlayerObservation);
			this->Controls->Add(this->buttonStay);
			this->Controls->Add(this->buttonHit);
			this->Controls->Add(this->buttonDeal);
			this->Controls->Add(this->labelDealerCardValue3);
			this->Controls->Add(this->labelDealerCardValue2);
			this->Controls->Add(this->labelDealerCardValue1);
			this->Controls->Add(this->labelPlayerCardValue3);
			this->Controls->Add(this->labelPlayerCardValue2);
			this->Controls->Add(this->labelPlayerCardValue1);
			this->Controls->Add(this->pictureBoxDealerCard3);
			this->Controls->Add(this->pictureBoxDealerCard2);
			this->Controls->Add(this->pictureBoxDealerCard1);
			this->Controls->Add(this->pictureBoxPlayerCard3);
			this->Controls->Add(this->pictureBoxPlayerCard2);
			this->Controls->Add(this->pictureBoxPlayerCard1);
			this->Controls->Add(this->buttonResults);
			this->Controls->Add(this->textBoxAccount);
			this->Controls->Add(this->labelEnterAccount);
			this->Controls->Add(this->buttonCredits);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->buttonInstructions);
			this->Controls->Add(this->pictureBoxBJGif);
			this->Controls->Add(this->buttonDateTime);
			this->Controls->Add(this->labelDateTime);
			this->Controls->Add(this->labelWelcome);
			this->Name = L"Form1";
			this->Text = L"Johnny\'s Black Jack Parlor";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxBJGif))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxPlayerCard1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxPlayerCard2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxPlayerCard3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxDealerCard1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxDealerCard2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxDealerCard3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	///////////////////////////////////////////////////////
	//				GLOBAL CONSTANTS
	///////////////////////////////////////////////////////
	static	const	String^	DEALER = "The Dealer";
	///////////////////////////////////////////////////////

	///////////////////////////////////////////////////////
	//				GLOBAL VARIABLES/OBJECTS
	///////////////////////////////////////////////////////
	DateTime	dateTimeStart;
	String^		playerName;
	String^		account;
	String^		password;

	static	array<CardType>^	deck				= gcnew array<CardType>(52);
	static	array<CardType>^	playersHand			= gcnew array<CardType>(3);
	static	array<CardType>^	dealersHand			= gcnew array<CardType>(3);
	static	array<GameHistory>^	playersHistory		= gcnew array<GameHistory>(255);
	static	array<GameHistory>^	dealersHistory		= gcnew array<GameHistory>(255);
	static	bool				cheatActivated		= false;
	static	bool				isTestOn			= false;
	static	int					playerCardValueSum	= -905; // lol
	static	int					dealerCardValueSum	= -905; // lol
	static	int					gameNumber			= 0;
	static	int					playerWins			= 0;
	static	int					playerLosses		= 0;
	static	int					dealerWins			= 0;
	static	int					dealerLosses		= 0;
	///////////////////////////////////////////////////////

/**************************************************************
***************************************************************
***                                                			***
***   START EVENT-DRIVEN FUNCTION DECLARATIONS/DEFINITIONS  ***
***                                                			***
***************************************************************
**************************************************************/

private: System::Void buttonAddACard_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (playerCardValueSum <= 0)
				 MessageBox::Show("Please \"Deal A Hand\" first", "Error");
			 else
				 addACardToHand();
		 }

private: System::Void buttonArrangeTheHand_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 arrangeTheHand();
		 }

private: System::Void buttonCheat_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 // We are cheaters
			 cheatActivated = true;

			 // Set game counter
			 gameNumber++;
			 labelGameNumber->Text = "Game #" + gameNumber;

			 // Update Stats
			 playerLosses = gameNumber - (gameNumber - dealerWins);
			 dealerLosses = gameNumber - (gameNumber - playerWins);
			 labelPlayerStats->Text = "Wins: " + playerWins 
									+ "\n\nLosses: " + playerLosses;
			 labelDealerStats->Text = "Wins: " + dealerWins 
									+ "\n\nLosses: " + dealerLosses;

			 // Reset hand value
			 playerCardValueSum = 0;
			 dealerCardValueSum = 0;

			 // Reset action label
			 labelDealerAction->Text = "";

			 // Mainly for the first deal, show card value labels
			 labelPlayerCardValue1->Visible = true;
			 labelPlayerCardValue2->Visible = true;
			 labelDealerCardValue1->Visible = true;
			 labelDealerCardValue2->Visible = true;

			 // Get rid of The Player's third card
			 labelPlayerCardValue3->Visible = false;
			 Array::Clear(playersHand, 2, 1);
			 pictureBoxPlayerCard3->Image = nullptr;
			 delete pictureBoxPlayerCard3->Image;

			 // Get rid of The Dealer's third card
			 labelDealerCardValue3->Visible = false;
			 Array::Clear(dealersHand, 2, 1);
			 pictureBoxDealerCard3->Image = nullptr;
			 delete pictureBoxDealerCard3->Image;

			 // Deal opening hands like cheaters do
			 for (int i = 100; i <= 106; i++)
				 dealCard(i);
		 }

private: System::Void buttonCredits_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 MessageBox::Show( 
				"*************************************************************************************\n"
				 "**************************************** ID INFO ************************************\n\n"
				 "	Programmer		:	Johnny Brinsko\n"
				 "	Assignment #		:	Final Project\n"
				 "	Assignment Name		:	Black Jack\n"
				 "	Course # and Title		:	CISC 192  - C++\n"
				 "	Class Meeting Time		:	TTh 9:35 - 12:40\n"
				 "	Instructor			:	Professor Forman\n"
				 "	Hours			:	29\n"
				 "	Difficulty			:	8\n"
				 "	Completion Date		:	12/13/2012\n"
				 "	Project Name		:	JohnnysBlackJack\n\n"
				 "**************************************************************************************\n"
				 "**************************************** CREDITS ************************************\n\n"
				 "	Thanks to Professor Forman, Tim, Jeramy, Mowlana, Matt\n"
				 "		for completing the learning triangle together\n\n"
				 "*************************************************************************************\n"
				 "**************************************** MEDIA *************************************\n\n"
				 "Background music during game:\n"
				 "http://www.youtube.com/watch?v=Y6ljFaKRTrI"
				 "\n\nFarewell music:\n"
				 "http://www.gamefront.com/files/12899141/Portal_Radio_Loop" 
				 "\n\nJose's cards from class, provided by Professor Forman"
				 "\n\nAnimated gif of blackjack dealing\n"
				 "	(used gifsoup.com to convert video to gif)\n"
				 "http://www.youtube.com/watch?v=V6WQrbauJEQ"
				 "\n\nBackground image:\n"
				 "http://www.customtablefelt.com/images/suited-poker-felt/suited-poker-table-felt-400x300.jpg"
				 );
		MessageBox::Show(
				 "*************************************************************************************\n"
				 "************************************** # OF STARS **********************************\n\n"
				 "15 stars\n\n"
				 "*************************************************************************************\n"
				 "**************************************** STARS *************************************\n\n"
				 "1. Specifically tell user whether the acct number or password or both are incorrect.\n"
				 "2. When displaying the deck, display the \"order\" number of the card next to the card info.\n"
				 "3. (2) Add the \"perfect\" shuffle as an additional shuffle option.\n"
				 "4. (2) Expand the \"shuffle check\" by identifying which cards ended up in the original position.\n"
				 "5. Handle the situation where the user selects Add A Card button before Deal A Hand.\n"
				 "6. Store the entire working deck by writing all info of each card to disk.\n"
				 "7. Also record information that maintains order which cards are to be dealt next.\n"
				 "8. Read the entire working deck from disk and use it to become the current working deck.\n"
				 "9. (2) Arrange the player's and dealer's hand at any time.\n"
				 "10. Add Dealer losing with 16! or winning with ...! in the History.\n"
				 "11. Add lowest game number in the History.\n"
				 "12. Don't do this star and explain how you did not do it."
				 );
		 }

private: System::Void buttonDateTime_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 displayDateTime();
		 }

private: System::Void buttonDeal_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 // Set game counter
			 gameNumber++;
			 labelGameNumber->Text = "Game #" + gameNumber;

			 // Update Stats
			 playerLosses = gameNumber - (gameNumber - dealerWins);
			 dealerLosses = gameNumber - (gameNumber - playerWins);
			 labelPlayerStats->Text = "Wins: " + playerWins 
									+ "\n\nLosses: " + playerLosses;
			 labelDealerStats->Text = "Wins: " + dealerWins 
									+ "\n\nLosses: " + dealerLosses;

			 // Reset hand value
			 playerCardValueSum = 0;
			 dealerCardValueSum = 0;

			 // Reset action label
			 labelDealerAction->Text = "";

			 // Mainly for the first deal, show card value labels
			 labelPlayerCardValue1->Visible = true;
			 labelPlayerCardValue2->Visible = true;
			 labelDealerCardValue1->Visible = true;
			 labelDealerCardValue2->Visible = true;

			 // Get rid of The Player's third card
			 labelPlayerCardValue3->Visible = false;
			 Array::Clear(playersHand, 2, 1);
			 pictureBoxPlayerCard3->Image = nullptr;
			 delete pictureBoxPlayerCard3->Image;

			 // Get rid of The Dealer's third card
			 labelDealerCardValue3->Visible = false;
			 Array::Clear(dealersHand, 2, 1);
			 pictureBoxDealerCard3->Image = nullptr;
			 delete pictureBoxDealerCard3->Image;

			 // Deal opening hands
			 for (int i = 1; i <= 4; i++)
				 dealCard(i);
		 }

private: System::Void buttonDealACard_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 dealACard(1);
		 }

private: System::Void buttonDealHand_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 playerCardValueSum = 0;

			 // Get rid of that third card in a really sloppy way
			 labelPlayerCardValue3->Visible = false;
			 Array::Clear(playersHand, 2, 1);
			 pictureBoxPlayerCard3->Image = nullptr;
			 delete pictureBoxPlayerCard3->Image;

			 dealAHand();
		 }

private: System::Void buttonDisplayDeck_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 displayDeck(deck);
		 }

private: System::Void buttonExit_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 ///////////////////////////////////////////////////////////////////
			 //				LOCAL VARIABLES/OBJECTS
			 ///////////////////////////////////////////////////////////////////
			 Windows::Forms::DialogResult	playAnother;
			 System::Media::SoundPlayer		soundPlayer( "wav/portalradio.wav");
			 ///////////////////////////////////////////////////////////////////

			 soundPlayer.PlayLooping();

			 if (dealerWins > playerWins)
				MessageBox::Show("Thanks for being such a good sport, " + playerName + ", in your " + gameNumber + " games.\n\n"
								+ "Too bad you won only " + playerWins + " game(s) while The Dealer won " + dealerWins + " game(s).");

			 else if (dealerWins == playerWins)
				 MessageBox::Show("After " + gameNumber + " games, " + playerName + ", you couldn't beat The Dealer.\n\n"
								+ "You won " + playerWins + " game(s) while The Dealer won " + dealerWins + " game(s) as well.");

			 else
				 MessageBox::Show("I know you had fun, " + playerName + ", in your " + gameNumber + " games.\n\n"
								+ "You outplayed The Dealer by winning " + playerWins + " game(s). The Dealer only won " + dealerWins + " game(s).");

			 playAnother = MessageBox::Show("Do you want to play another game?", "Are you sure?", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			 if (playAnother == Windows::Forms::DialogResult::No)
				 Close();
			 
		 }

private: System::Void buttonHistory_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 ///////////////////////////////////////////////////////////////////////
			 //				LOCAL VARIABLES/OBJECTS
			 ///////////////////////////////////////////////////////////////////////
			 String^				history;
			 String^				prep;
			 int					lowestTotal;
			 int					highestTotal;
			 int					lowestGame;
			 int					busts			= 0;
			 array<GameHistory>^	sortedHistory	= gcnew array<GameHistory>(255);
			 ///////////////////////////////////////////////////////////////////////

			 // FIRST MESSAGE BOX
			 // Append (example) In 5 games, playerName has won 3 times
			 history = "	" + playerName + "'s Black Jack History\n\n"
					 + "In " + gameNumber + " games,\n";
			 history += playerName + " has won " + playerWins + " time(s)\n"
					  + playerName + " has lost " + playerLosses + " time(s)\n";
			 
			 // Prep the game winning or losing results for player
			 prep = "";
			 for (int i = 0; i < playersHistory->Length; i++)
			 {
				 if (playersHistory[i].histGameNumber > 0)
					 prep += "Game #" + playersHistory[i].histGameNumber + " ends with " 
						  + playerName + " " + playersHistory[i].histWinOrLose + " with " 
						  + playersHistory[i].histHandTotal + "!\n";
			 }

			 // Append (example) Game #1 ends with playerName winning with 21!
			 history += "\n" + prep;

			 // Prep the game winning or losing results for The Dealer
			 prep = "";
			 for (int i = 0; i < dealersHistory->Length; i++)
			 {
				 if (dealersHistory[i].histGameNumber > 0)
					 prep += "Game #" + dealersHistory[i].histGameNumber + " ends with " 
						  + DEALER + " " + dealersHistory[i].histWinOrLose + " with " 
						  + dealersHistory[i].histHandTotal + "!\n";
			 }

			 // Append (example) Game #1 ends with The Dealer winning with 21!
			 history += "\n" + prep;

			 // Finally, the message box appears
			 MessageBox::Show(history, playerName + "'s Black Jack History");

			 // SECOND MESSAGE BOX
			 // New history to display card totals
			 history = "So, in the " + gameNumber + " games, " + playerName + "'s card totals were:\n";

			 // Prep the card totals for display
			 prep = "";
			 for (int i = 0; i < playersHistory->Length; i++)
			 {
				 if (playersHistory[i].histGameNumber > 0)
					 prep += playersHistory[i].histHandTotal + " ";
			 }

			 // Append the player's card totals in no order
			 history += "	" + prep + "\n\n";

			 // Getting ready for sorting the card totals
			 history += "From lowest to highest, card totals were:\n";

			 // Copy playersHistory to sortedHistory
			 for (int i = 0; i < sortedHistory->Length; i++)
				 sortedHistory[i] = playersHistory[i];

			 // Insertion Sort
			 for (int i = 0; i < sortedHistory->Length - 1; i++)
			 {
			 	int vacant;
			 	GameHistory temp = sortedHistory[i+1];
			 	for (vacant = i+1; ((vacant > 0) && (sortedHistory[vacant-1].histHandTotal > temp.histHandTotal)); vacant--)
			 		sortedHistory[vacant] = sortedHistory[vacant-1];
			 	sortedHistory[vacant] = temp;
			 }

			 // Prep the output of our sorted array
			 prep = "";
			 for (int i = 0; i < sortedHistory->Length; i++)
			 {
				 if (sortedHistory[i].histGameNumber > 0)
					 prep += sortedHistory[i].histHandTotal + " ";
			 }

			 // Append the player's card totals from lowest to highest
			 history += "	" + prep + "\n\n";

			 // Find the lowest card total and corresponding game number for the player
			 lowestTotal = 99;
			 for (int i = 0; i < playersHistory->Length; i++)
			 {
				 if (playersHistory[i].histHandTotal > 0)
					 if (playersHistory[i].histHandTotal < lowestTotal)
					 {
						 lowestTotal = playersHistory[i].histHandTotal;
						 lowestGame = playersHistory[i].histGameNumber;
					 }
			 }

			 // Find the highest card total for the player
			 highestTotal = 0;
			 for (int i = 0; i < playersHistory->Length; i++)
			 {
				 if (playersHistory[i].histHandTotal > highestTotal)
					 if (playersHistory[i].histHandTotal < 32) // Filter the crazy high numbers
						 highestTotal = playersHistory[i].histHandTotal;
			 }

			 // Append the player's lowest and highest card totals
			 history += "With the lowest total of " + lowestTotal + " and the highest total of " + highestTotal + "\n";

			 // Count how many times the player busted
			 for (int i = 0; i < playersHistory->Length; i++)
			 {
				 if (playersHistory[i].histHandTotal > 21)
					 busts++;
			 }

			 // Append the player's number of busts
			 history += "And with " + busts + " bust(s)\n";

			 // Append the player's lowest game number occurance
			 history += "And the lowest game was Game #" + lowestGame + "\n";

			 // Finally, the second message box appears
			 MessageBox::Show(history, playerName + "'s Black Jack History");
		 }

private: System::Void buttonHit_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 pictureBoxPlayerCard3->Visible = true;
			 labelPlayerCardValue3->Visible = true;
			 dealCard(5);

			 pictureBoxDealerCard3->Visible = true;
			 labelDealerCardValue3->Visible = true;
			 dealCard(6);
		 }

private: System::Void buttonInstructions_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 MessageBox::Show("Login and click the DEAL button. Press HIT if you want another card.\n"
							+ "Press STAY if you don't want another card.\n\n"
							+ "You can set up certain scenarios with the CHEAT feature.\n\n"
							+ "After the player and dealer have been randomly dealt two cards each:\n\n"
							+ "If Black Jack occurs (= first two cards add up to 21) for either the player "
							+ "or the dealer, then the game ends immediately and the Black Jacker is the winner.\n\n"
							+ "Whenever the player goes \"bust\", the dealer immediately wins.\n\n"
							+ "Player has first option to get \"hit\"; after player's last hit, it's the dealer's turn.\n\n"
							+ "Each participant can get a maximum of 3 cards.\n\n"
							+ "The dealer stays on 16 or higher and hits under 16.\n\n"
							+ "If the player has not gone \"bust\" and the dealer does \"bust\", then the player wins immediately.\n\n"
							+ "If neither the player nor dealer has gone \"bust\", then the higher total wins.\n\n"
							+ "In case of a tie, the dealer wins." 
							, "Instructions" );
			 MessageBox::Show("If you logged in using the master password, enable/disable the test buttons by clicking on the button in the top right.\n\n"
							+ "You must set up the deck first.\n\n"
							+ "You may display the deck at any time by clicking on the Display Deck button.\n\n"
							+ "You may shuffle the deck at any time by clicking on one of the two Shuffle Deck buttons.\n\n"
							+ "The Shuffle Deck button uses random swap. The Shuffle Deck Perfect cuts the deck in half and interleaves the cards one by one. Eight perfect shuffles yields where you started.\n\n"
							+ "Deal A Card button will deal a card to the top left picture box.\n\n"
							+ "Deal A Hand button will deal two cards on the left side.\n\n"
							+ "Add A Card button adds a third card to a hand already dealt with Deal A Hand.\n\n"
							+ "Arrange The Hand at any time from low to high and alphabetical suit order.\n\n"
							+ "Store Deck On Disk will write the current working deck to dat/workingDeck.dat\n\n"
							+ "Load Deck From Disk will read dat/workingDeck.dat and create a working deck for play.\n\n"
							+ "You may edit that file by hand. The layout is:\ncardValue cardName cardSuit cardImageIndex\n\n"
							+ "Return button will hide the test buttons except for the Display Deck button.\n\n"
							+ "If logged in using blackjack password, test buttons are disabled." 
							, "Instructions (Continued)" );
		 }

private: System::Void buttonLoadDeck_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 loadDeck();
		 }

private: System::Void buttonLogin_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 buttonLogin->Visible = false;
			 buttonSubmit->Visible = true;
			 labelEnterAccount->Visible = true;
			 textBoxAccount->Visible = true;
			 labelEnterPassword->Visible = true;
			 textBoxPassword->Visible = true;
			 textBoxAccount->Focus();
		 }

private: System::Void buttonResults_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (dealerWins > playerWins)
				 MessageBox::Show("In the " + gameNumber + " games played,\n" + playerName + " has won "
							+ playerWins + " game(s)\nThe Dealer has won " + dealerWins + " game(s)\n"
							+ "So far, The Dealer has won more games!");
			 else if (dealerWins == playerWins)
				 MessageBox::Show("In the " + gameNumber + " games played,\n" + playerName + " has won "
							+ playerWins + " game(s)\nThe Dealer has won " + dealerWins + " game(s)\n"
			 				+ "So far, " + playerName + " has won the same amount of games as The Dealer.");
			 else
				 MessageBox::Show("In the " + gameNumber + " games played,\n" + playerName + " has won "
							+ playerWins + " game(s)\nThe Dealer has won " + dealerWins + " game(s)\n"
			 				+ playerName + " has won more games!");
		 }

private: System::Void buttonReturn_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 buttonTestFunctions_Click(sender, e);
		 }

private: System::Void buttonSetUpDeck_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 setUpDeckByValue();
		 }

private: System::Void buttonShuffleDeck_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 shuffleDeck();
		 }

private: System::Void buttonShuffleDeckPerfect_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 shuffleDeckPerfect();
		 }

private: System::Void buttonStay_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 pictureBoxDealerCard3->Visible = true;
			 labelDealerCardValue3->Visible = true;
			 dealCard(6);
		 }

private: System::Void buttonStoreDeck_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 storeDeck();
		 }

private: System::Void buttonSubmit_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 account = textBoxAccount->Text;
			 password = textBoxPassword->Text;

			 // Account Number and Password are both invalid and report to user
			 if (!verifyAccount(account) && !isValidPassword(password))
				 MessageBox::Show("Both the account number and password is invalid. Please try again . . .", "Invalid Account Number and Password");

			 // One is valid, figure out which one is invalid and report to user
			 else if (!verifyAccount(account) || !isValidPassword(password))
			 {
				 if (isValidPassword(password))
					 MessageBox::Show("The account number is not valid. Please try again . . .", "Invalid Account Number");
				 else if (verifyAccount(account))
					 MessageBox::Show("The password is not valid. Please try again . . .", "Invalid Password");
			 }

			 // Account Number and Password are both good
			 else if (verifyAccount(account) && isValidPassword(password))
			 {
				 MessageBox::Show("Thanks for joining us, " + playerName);

				 // Setup the initial game layout
				 buttonSubmit->Visible = false;
				 labelEnterAccount->Visible = false;
				 textBoxAccount->Visible = false;
				 labelEnterPassword->Visible = false;
				 textBoxPassword->Visible = false;
				 buttonLogin->Visible = false;
				 buttonResults->Visible = true;
				 buttonDeal->Visible = true;
				 buttonHit->Visible = true;
				 buttonStay->Visible = true;
				 labelGameNumber->Visible = true;
				 labelPlayerObservation->Visible = true;
				 labelPlayerObservation->Text = playerName + "'s Hand Value: ";
				 labelDealerObservation->Visible = true;
				 labelDealerAction->Visible = true;
				 buttonCheat->Visible = true;
				 comboBoxCheat->Visible = true;
				 labelSelectCheat->Visible = true;
				 labelPlayerStats->Visible = true;
				 labelDealerStats->Visible = true;
				 buttonHistory->Visible = true;

				 // If master password was entered, also do:
				 if (isMaster(password))
				 {
					 buttonTestFunctions->Visible = true;
					 buttonDisplayDeck->Visible = true;
					 MessageBox::Show("You entered the master password. You should know there are test functions.\n"
									+ "Show the test buttons by clicking the button in the top right.", "Master pwd Success");
				 }

				 // Since master password was not entered,
				 // apply required functions to prep the game
				 else
				 {
					 setUpDeckByValue();
					 shuffleDeck();
				 }
			 }

			 // Something went wrong
			 else
				 MessageBox::Show("oops\nThat wasn't supposed to happen");
		 }

private: System::Void buttonTestFunctions_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (isTestOn == false)
			 {
				 buttonTestFunctions->Text = "Hide Test Buttons";
				 buttonSetUpDeck->Visible = true;
				 buttonShuffleDeck->Visible = true;
				 buttonDealACard->Visible = true;
				 buttonDealAHand->Visible = true;
				 buttonAddACard->Visible = true;
				 buttonArrangeTheHand->Visible = true;
				 buttonStoreDeck->Visible = true;
				 buttonLoadDeck->Visible = true;
				 buttonReturn->Visible = true;
				 buttonShuffleDeckPerfect->Visible = true;
			 }

			 else
			 {
				 buttonTestFunctions->Text = "Show Test Buttons";
				 buttonSetUpDeck->Visible = false;
				 buttonShuffleDeck->Visible = false;
				 buttonDealACard->Visible = false;
				 buttonDealAHand->Visible = false;
				 buttonAddACard->Visible = false;
				 buttonArrangeTheHand->Visible = false;
				 buttonStoreDeck->Visible = false;
				 buttonLoadDeck->Visible = false;
				 buttonReturn->Visible = false;
				 buttonShuffleDeckPerfect->Visible = false;
			 }

			 isTestOn = !isTestOn;
		 }

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 ///////////////////////////////////////////////////////////////////
			 //				LOCAL VARIABLES/OBJECTS
			 ///////////////////////////////////////////////////////////////////
			 System::Media::SoundPlayer		soundPlayer( "wav/Portal.wav");
			 ///////////////////////////////////////////////////////////////////

			 soundPlayer.Play();
		 }

/**************************************************************
***************************************************************
***                                                			***
***   END EVENT-DRIVEN FUNCTION DECLARATIONS/DEFINITIONS    ***
***                                                			***
***************************************************************
**************************************************************/

/**************************************************************
***************************************************************
***                                                			***
***			  START NON EVENT-DRIVEN FUNCTIONS				***
***                                                			***
***************************************************************
**************************************************************/

void addACardToHand()
{
	dealACard(5);
}

void arrangeTheHand()
{
	///////////////////////////////////////////////////////
	//				LOCAL VARIABLES/OBJECTS
	///////////////////////////////////////////////////////
	int	 cardPasted	= 0;
	///////////////////////////////////////////////////////

	// Bubble sort
	//for (int i = 0; i < playersHand->Length - 1; i++)
	//{
	//	for (int j = 0; j < playersHand->Length - 1 - i; j++)
	//	{
	//		if (playersHand[j].cardImageIndex > playersHand[j+1].cardImageIndex)
	//		{
	//			CardType table = playersHand[j];
	//			playersHand[j] = playersHand[j+1];
	//			playersHand[j+1] = table;
	//		}
	//	}
	//}
	
	// Insertion Sort
	for (int i = 0; i < playersHand->Length - 1; i++)
	{
		int vacant;
		CardType temp = playersHand[i+1];
		for (vacant = i+1; ((vacant > 0) && (playersHand[vacant-1].cardImageIndex > temp.cardImageIndex)); vacant--)
			playersHand[vacant] = playersHand[vacant-1];
		playersHand[vacant] = temp;
	}

	// If an element in playersHand is null, move to playersHand[2]
	if (playersHand[0].cardValue == 0)
	{
		CardType table = playersHand[0];
		for (int i = 1; i < playersHand->Length; i++)
			playersHand[i-1] = playersHand[i];
		playersHand[playersHand->Length - 1] = table;
	}

	// Put the card images and card labels in the right spot
	for (int i = 0; i < playersHand->Length; i++)
	{
		// If the third card wasn't dealt, ignore it
		if (playersHand[i].cardValue > 0)
		{
			if (cardPasted == 0)
			{
				labelPlayerCardValue1->Text = playersHand[i].cardName + " of " + playersHand[i].cardSuit + " - " + playersHand[i].cardValue;
				pictureBoxPlayerCard1->Image = imageListCards->Images[playersHand[i].cardImageIndex];
				cardPasted++;
			}
			else if (cardPasted == 1)
			{
				labelPlayerCardValue2->Text = playersHand[i].cardName + " of " + playersHand[i].cardSuit + " - " + playersHand[i].cardValue;
				pictureBoxPlayerCard2->Image = imageListCards->Images[playersHand[i].cardImageIndex];
				cardPasted++;
			}
			else if (cardPasted == 2)
			{
				labelPlayerCardValue3->Text = playersHand[i].cardName + " of " + playersHand[i].cardSuit + " - " + playersHand[i].cardValue;
				pictureBoxPlayerCard3->Image = imageListCards->Images[playersHand[i].cardImageIndex];
			}
		}
	}

	// Arrange the dealer's hand if there are cards
	if (dealersHand[1].cardValue > 0)
	{
		// Insertion Sort
		for (int i = 0; i < dealersHand->Length - 1; i++)
		{
			int vacant;
			CardType temp = dealersHand[i+1];
			for (vacant = i+1; ((vacant > 0) && (dealersHand[vacant-1].cardImageIndex > temp.cardImageIndex)); vacant--)
				dealersHand[vacant] = dealersHand[vacant-1];
			dealersHand[vacant] = temp;
		}

		// If an element in playersHand is null, move to playersHand[2]
		if (dealersHand[0].cardValue == 0)
		{
			CardType table = dealersHand[0];
			for (int i = 1; i < dealersHand->Length; i++)
				dealersHand[i-1] = dealersHand[i];
			dealersHand[dealersHand->Length - 1] = table;
		}

		// Refresh the variable for The Dealer
		cardPasted = 0;

		// Put the card images and card labels in the right spot
		for (int i = 0; i < dealersHand->Length; i++)
		{
			// If the third card wasn't dealt, ignore it
			if (dealersHand[i].cardValue > 0)
			{
				if (cardPasted == 0)
				{
					labelDealerCardValue1->Text = dealersHand[i].cardName + " of " + dealersHand[i].cardSuit + " - " + dealersHand[i].cardValue;
					pictureBoxDealerCard1->Image = imageListCards->Images[dealersHand[i].cardImageIndex];
					cardPasted++;
				}
				else if (cardPasted == 1)
				{
					labelDealerCardValue2->Text = dealersHand[i].cardName + " of " + dealersHand[i].cardSuit + " - " + dealersHand[i].cardValue;
					pictureBoxDealerCard2->Image = imageListCards->Images[dealersHand[i].cardImageIndex];
					cardPasted++;
				}
				else if (cardPasted == 2)
				{
					labelDealerCardValue3->Text = dealersHand[i].cardName + " of " + dealersHand[i].cardSuit + " - " + dealersHand[i].cardValue;
					pictureBoxDealerCard3->Image = imageListCards->Images[dealersHand[i].cardImageIndex];
				}
			}
		}
	}
}

void cheatWithCard(int cardImageSlot)
{
	///////////////////////////////////////////////////////
	//				LOCAL VARIABLES/OBJECTS
	///////////////////////////////////////////////////////
	CardType table;
	///////////////////////////////////////////////////////

	// Find the desired card in the working deck and swap it with top card of deck
	for (int i = 0; i < deck->Length; i++)
	{
		if (deck[i].cardImageIndex == cardImageSlot)
		{
			table = deck[i];
			deck[i] = deck[0];
			deck[0] = table;
		}
	}
}

bool check21(int sum)
{
	return (sum == 21);
}

void dealCard(int cardToDeal)
{
	///////////////////////////////////////////////////////
	//				LOCAL VARIABLES/OBJECTS
	///////////////////////////////////////////////////////
	bool		cardWasDealt = true;
	///////////////////////////////////////////////////////

	// CHEAT Button Activated
	if (cheatActivated)
	{
		labelWelcome->Text = "I'm a Cheater";

		if (comboBoxCheat->Text == "Player gets BlackJack")
		{
			if (cardToDeal == 100)
			{
				cheatWithCard(47); // King
				cardToDeal = 1;
			}

			else if (cardToDeal == 101)
			{
				cheatWithCard(48); // Ace
				cardToDeal = 2;
			}

			else if (cardToDeal == 102)
			{
				cheatWithCard(0); // Two
				cardToDeal = 3;
			}

			else if (cardToDeal == 103)
			{
				cheatWithCard(1); // Two
				cardToDeal = 4;
			}
		}

		else if (comboBoxCheat->Text == "Dealer gets BlackJack")
		{
			if (cardToDeal == 100)
			{
				cheatWithCard(0); // Two
				cardToDeal = 1;
			}

			else if (cardToDeal == 101)
			{
				cheatWithCard(1); // Two
				cardToDeal = 2;
			}

			else if (cardToDeal == 102)
			{
				cheatWithCard(47); // King
				cardToDeal = 3;
			}

			else if (cardToDeal == 103)
			{
				cheatWithCard(48); // Ace
				cardToDeal = 4;
			}
		}

		else if (comboBoxCheat->Text == "Both get BlackJack")
		{
			if (cardToDeal == 100)
			{
				cheatWithCard(47); // King
				cardToDeal = 1;
			}

			else if (cardToDeal == 101)
			{
				cheatWithCard(48); // Ace
				cardToDeal = 2;
			}

			else if (cardToDeal == 102)
			{
				cheatWithCard(46); // King
				cardToDeal = 3;
			}

			else if (cardToDeal == 103)
			{
				cheatWithCard(49); // Ace
				cardToDeal = 4;
			}
		}

		else if (comboBoxCheat->Text == "Player Busts and Dealer under threshold")
		{
			if (cardToDeal == 100)
			{
				cheatWithCard(51); // Ace
				cardToDeal = 1;
			}

			else if (cardToDeal == 101)
			{
				cheatWithCard(50); // Ace
				cardToDeal = 2;
			}

			else if (cardToDeal == 102)
			{
				cheatWithCard(0); // Two
				cardToDeal = 3;
			}

			else if (cardToDeal == 103)
			{
				cheatWithCard(1); // Two
				cardToDeal = 4;
			}
		}

		else if (comboBoxCheat->Text == "Player Busts and Dealer within threshold")
		{
			if (cardToDeal == 100)
			{
				cheatWithCard(51); // Ace
				cardToDeal = 1;
			}

			else if (cardToDeal == 101)
			{
				cheatWithCard(50); // Ace
				cardToDeal = 2;
			}

			else if (cardToDeal == 102)
			{
				cheatWithCard(47); // King
				cardToDeal = 3;
			}

			else if (cardToDeal == 103)
			{
				cheatWithCard(46); // King
				cardToDeal = 4;
			}
		}

		else if (comboBoxCheat->Text == "Dealer Busts and Player does not")
		{
			if (cardToDeal == 100)
			{
				cheatWithCard(0); // Two
				cardToDeal = 1;
			}

			else if (cardToDeal == 101)
			{
				cheatWithCard(1); // Two
				cardToDeal = 2;
			}

			else if (cardToDeal == 102)
			{
				cheatWithCard(51); // Ace
				cardToDeal = 3;
			}

			else if (cardToDeal == 103)
			{
				cheatWithCard(50); // Ace
				cardToDeal = 4;
			}
		}

		else if (comboBoxCheat->Text == "Player has 10 and Dealer has 10")
		{
			if (cardToDeal == 100)
			{
				cheatWithCard(12); // Five
				cardToDeal = 1;
			}

			else if (cardToDeal == 101)
			{
				cheatWithCard(13); // Five
				cardToDeal = 2;
			}

			else if (cardToDeal == 102)
			{
				cheatWithCard(14); // Five
				cardToDeal = 3;
			}

			else if (cardToDeal == 103)
			{
				cheatWithCard(15); // Five
				cardToDeal = 4;
			}
		}

		else if (comboBoxCheat->Text == "Player has 10 and Dealer has 15")
		{
			if (cardToDeal == 100)
			{
				cheatWithCard(12); // Five
				cardToDeal = 1;
			}

			else if (cardToDeal == 101)
			{
				cheatWithCard(13); // Five
				cardToDeal = 2;
			}

			else if (cardToDeal == 102)
			{
				cheatWithCard(14); // Five
				cardToDeal = 3;
			}

			else if (cardToDeal == 103)
			{
				cheatWithCard(47); // King
				cardToDeal = 4;
			}
		}

		else if (comboBoxCheat->Text == "Player has 10 and Dealer has 16")
		{
			if (cardToDeal == 100)
			{
				cheatWithCard(12); // Five
				cardToDeal = 1;
			}

			else if (cardToDeal == 101)
			{
				cheatWithCard(13); // Five
				cardToDeal = 2;
			}

			else if (cardToDeal == 102)
			{
				cheatWithCard(16); // Six
				cardToDeal = 3;
			}

			else if (cardToDeal == 103)
			{
				cheatWithCard(47); // King
				cardToDeal = 4;
			}
		}

		else if (comboBoxCheat->Text == "Player has 20 and Dealer has 10")
		{
			if (cardToDeal == 100)
			{
				cheatWithCard(47); // King
				cardToDeal = 1;
			}

			else if (cardToDeal == 101)
			{
				cheatWithCard(46); // King
				cardToDeal = 2;
			}

			else if (cardToDeal == 102)
			{
				cheatWithCard(12); // Five
				cardToDeal = 3;
			}

			else if (cardToDeal == 103)
			{
				cheatWithCard(13); // Five
				cardToDeal = 4;
			}
		}

		else if (comboBoxCheat->Text == "Player has 20 and Dealer has 15")
		{
			if (cardToDeal == 100)
			{
				cheatWithCard(47); // King
				cardToDeal = 1;
			}

			else if (cardToDeal == 101)
			{
				cheatWithCard(46); // King
				cardToDeal = 2;
			}

			else if (cardToDeal == 102)
			{
				cheatWithCard(12); // Five
				cardToDeal = 3;
			}

			else if (cardToDeal == 103)
			{
				cheatWithCard(45); // King
				cardToDeal = 4;
			}
		}

		else if (comboBoxCheat->Text == "Player has 20 and Dealer has 16")
		{
			if (cardToDeal == 100)
			{
				cheatWithCard(47); // King
				cardToDeal = 1;
			}

			else if (cardToDeal == 101)
			{
				cheatWithCard(46); // King
				cardToDeal = 2;
			}

			else if (cardToDeal == 102)
			{
				cheatWithCard(16); // Six
				cardToDeal = 3;
			}

			else if (cardToDeal == 103)
			{
				cheatWithCard(45); // King
				cardToDeal = 4;
			}
		}
	} // End of CHEAT patch

	// Deal cards 1 and 2 to Player. Then deal cards 3 and 4 to Dealer. 
	//  Card 5 goes to Player. Card 6 goes to Dealer.
	switch (cardToDeal)
	{
		case 1:
			labelPlayerCardValue1->Text = deck[0].cardName + " of " + deck[0].cardSuit + " - " + deck[0].cardValue.ToString();
			pictureBoxPlayerCard1->Image = imageListCards->Images[deck[0].cardImageIndex];
			playerCardValueSum += deck[0].cardValue;
			playersHand[0] = deck[0];
			break;

		case 2:
			labelPlayerCardValue2->Text = deck[0].cardName + " of " + deck[0].cardSuit + " - " + deck[0].cardValue.ToString();
			pictureBoxPlayerCard2->Image = imageListCards->Images[deck[0].cardImageIndex];
			playerCardValueSum += deck[0].cardValue;
			labelPlayerObservation->Text = playerName + "'s hand value: " + playerCardValueSum.ToString();
			playersHand[1] = deck[0];
			break;

		case 3:
			labelDealerCardValue1->Text = deck[0].cardName + " of " + deck[0].cardSuit + " - " + deck[0].cardValue.ToString();
			pictureBoxDealerCard1->Image = imageListCards->Images[deck[0].cardImageIndex];
			dealerCardValueSum += deck[0].cardValue;
			dealersHand[0] = deck[0];
			break;

		case 4:
			labelDealerCardValue2->Text = deck[0].cardName + " of " + deck[0].cardSuit + " - " + deck[0].cardValue.ToString();
			pictureBoxDealerCard2->Image = imageListCards->Images[deck[0].cardImageIndex];
			dealerCardValueSum += deck[0].cardValue;
			labelDealerObservation->Text = "Dealer's hand value: " + dealerCardValueSum.ToString();
			dealersHand[1] = deck[0];

			// If dealer has blackjack, the game is over
			if (check21(dealerCardValueSum))
			{
				labelDealerAction->Text = "Game #" + gameNumber + " ends: " + playerName + " has " 
										+ playerCardValueSum + " and The Dealer has " + dealerCardValueSum + "\n";
				labelDealerAction->Text += "The Dealer has BlackJack. Game Over :(\n";
				labelDealerAction->Text += playerName + " has " + playerCardValueSum + " and The Dealer has " + dealerCardValueSum
										 +  "\nTherefore, The Dealer wins.";
				dealerWins++;
				updateHistory(playerCardValueSum, dealerCardValueSum, "dealer");
			}

			// If player has blackjack but not the dealer, the player wins
			else if (check21(playerCardValueSum))
			{
				labelDealerAction->Text = "Game #" + gameNumber + " ends: " + playerName + " has " 
										+ playerCardValueSum + " and The Dealer has " + dealerCardValueSum + "\n";
				labelDealerAction->Text += "Congratulations on Black Jack. You Win!\n";
				labelDealerAction->Text += playerName + " has " + playerCardValueSum + " and The Dealer has " + dealerCardValueSum
										 +  "\nTherefore, " + playerName + " wins.";
				playerWins++;
				updateHistory(playerCardValueSum, dealerCardValueSum, "player");
			}

			// If player busts on first two cards
			else if (playerCardValueSum > 21)
			{
				labelDealerAction->Text = "Game #" + gameNumber + " ends: " + playerName + " has " 
										+ playerCardValueSum + " and The Dealer has " + dealerCardValueSum + "\n";
				labelDealerAction->Text += "Sorry, you busted. You lose :(\n";
				labelDealerAction->Text += playerName + " has " + playerCardValueSum + " and The Dealer has " + dealerCardValueSum
										 +  "\nTherefore, The Dealer wins.";
				dealerWins++;
				updateHistory(playerCardValueSum, dealerCardValueSum, "dealer");
			}

			// If Dealer busts on first two cards
			else if (dealerCardValueSum > 21)
			{
				labelDealerAction->Text = "Game #" + gameNumber + " ends: " + playerName + " has " 
										+ playerCardValueSum + " and The Dealer has " + dealerCardValueSum + "\n";
				labelDealerAction->Text += "The Dealer busted, so you win!\n";
				labelDealerAction->Text += playerName + " has " + playerCardValueSum + " and The Dealer has " + dealerCardValueSum
										 +  "\nTherefore, " + playerName + " wins.";
				playerWins++;
				updateHistory(playerCardValueSum, dealerCardValueSum, "player");
			}

			// Dealer takes no card
			else if (dealerCardValueSum >= 16)
				labelDealerAction->Text = "The Dealer has " + dealerCardValueSum + " and stands on 16 or higher, "
										+ "so The Dealer will take no card.";

			// Dealer takes a card
			else
				labelDealerAction->Text = "The Dealer has " + dealerCardValueSum + " and hits on 15 or lower, "
										+ "so The Dealer will take another card.";

			break;

		case 5:
			labelPlayerCardValue3->Text = deck[0].cardName + " of " + deck[0].cardSuit + " - " + deck[0].cardValue.ToString();
			pictureBoxPlayerCard3->Image = imageListCards->Images[deck[0].cardImageIndex];
			playerCardValueSum += deck[0].cardValue;
			labelPlayerObservation->Text = playerName + "'s hand value: " + playerCardValueSum.ToString();
			playersHand[2] = deck[0];
			break;

		case 6:
			// It's all over if the player busts
			if (playerCardValueSum > 21)
			{
				// Hide the third card
				pictureBoxDealerCard3->Visible = false;
				labelDealerCardValue3->Visible = false;

				// Game is over
				labelDealerAction->Text = "Game #" + gameNumber + " ends: " + playerName + " has " 
										+ playerCardValueSum + " and The Dealer has " + dealerCardValueSum + "\n";
				labelDealerAction->Text += "You busted, so the game is over.\n";
				labelDealerAction->Text += playerName + " has " + playerCardValueSum + " and The Dealer has " + dealerCardValueSum
										 +  "\nTherefore, The Dealer wins.";
				dealerWins++;
				updateHistory(playerCardValueSum, dealerCardValueSum, "dealer");
				cardWasDealt = false;
				break;
			}

			// Player is closer to 21 (but not over) and Dealer is within threshold
			else if (playerCardValueSum > dealerCardValueSum && playerCardValueSum <= 21 && dealerCardValueSum >= 16)
			{
				// Hide the third card
				labelDealerCardValue3->Visible = false;

				// Game is over
				labelDealerAction->Text = "Game #" + gameNumber + " ends: " + playerName + " has " 
										+ playerCardValueSum + " and The Dealer has " + dealerCardValueSum + "\n";
				labelDealerAction->Text += "Winner Winner, Chicken Dinner\n";
				labelDealerAction->Text += playerName + " has " + playerCardValueSum + " and The Dealer has " + dealerCardValueSum
										 +  "\nTherefore, " + playerName + " wins.";
				playerWins++;
				updateHistory(playerCardValueSum, dealerCardValueSum, "player");
				cardWasDealt = false;
				break;
			}

			// Dealer is within threshold but Player does not have higher score
			else if (playerCardValueSum <= dealerCardValueSum && dealerCardValueSum >= 16)
			{
				// Hide the third card
				pictureBoxDealerCard3->Visible = false;
				labelDealerCardValue3->Visible = false;

				labelDealerAction->Text = "Game #" + gameNumber + " ends: " + playerName + " has " 
										+ playerCardValueSum + " and The Dealer has " + dealerCardValueSum + "\n";
				labelDealerAction->Text += "That was a bad beat.\n";
				labelDealerAction->Text += playerName + " has " + playerCardValueSum + " and The Dealer has " + dealerCardValueSum
										 +  "\nTherefore, The Dealer wins.";
				dealerWins++;
				updateHistory(playerCardValueSum, dealerCardValueSum, "dealer");
				cardWasDealt = false;
				break;
			}

			// Dealer takes a third card if hand value is less than 16
			else
			{
				labelDealerCardValue3->Text = deck[0].cardName + " of " + deck[0].cardSuit + " - " + deck[0].cardValue.ToString();
				pictureBoxDealerCard3->Image = imageListCards->Images[deck[0].cardImageIndex];
				dealerCardValueSum += deck[0].cardValue;
				labelDealerObservation->Text = "Dealer's hand value: " + dealerCardValueSum.ToString();
				dealersHand[2] = deck[0];
			}

			/************** Now all cards have been dealt ***************/

			// The Dealer takes a third card and busts
			if (dealerCardValueSum > 21)
			{
				labelDealerAction->Text = "Game #" + gameNumber + " ends: " + playerName + " has " 
										+ playerCardValueSum + " and The Dealer has " + dealerCardValueSum + "\n";
				labelDealerAction->Text += "The Dealer has busted. You win!\n";
				labelDealerAction->Text += playerName + " has " + playerCardValueSum + " and The Dealer has " + dealerCardValueSum
										 +  "\nTherefore, " + playerName + " wins.";
				playerWins++;
				updateHistory(playerCardValueSum, dealerCardValueSum, "player");
			}

			// Player's total is greater than Dealer's but isn't a bust
			else if (playerCardValueSum > dealerCardValueSum && playerCardValueSum <= 21)
			{
				labelDealerAction->Text = "Game #" + gameNumber + " ends: " + playerName + " has " 
										+ playerCardValueSum + " and The Dealer has " + dealerCardValueSum + "\n";
				labelDealerAction->Text += "Winner Winner, Chicken Dinner\n";
				labelDealerAction->Text += playerName + " has " + playerCardValueSum + " and The Dealer has " + dealerCardValueSum
										 +  "\nTherefore, " + playerName + " wins.";
				playerWins++;
				updateHistory(playerCardValueSum, dealerCardValueSum, "player");
			}

			// Player stands when Dealer is within threshold
			else if (playerCardValueSum <= 15 && dealerCardValueSum >= 16)
			{
				// Hide the third card
				labelDealerCardValue3->Visible = false;

				labelDealerAction->Text = "Game #" + gameNumber + " ends: " + playerName + " has " 
										+ playerCardValueSum + " and The Dealer has " + dealerCardValueSum + "\n";
				labelDealerAction->Text += "You lose. You really should've hit.\n";
				labelDealerAction->Text += playerName + " has " + playerCardValueSum + " and The Dealer has " + dealerCardValueSum
										 +  "\nTherefore, The Dealer wins.";
				dealerWins++;
				updateHistory(playerCardValueSum, dealerCardValueSum, "dealer");
			}

			// There's no other way the Player can win
			else
			{
				labelDealerAction->Text = "Game #" + gameNumber + " ends: " + playerName + " has " 
										+ playerCardValueSum + " and The Dealer has " + dealerCardValueSum + "\n";
				labelDealerAction->Text += "Sorry, you lost this round.\n";
				labelDealerAction->Text += playerName + " has " + playerCardValueSum + " and The Dealer has " + dealerCardValueSum
										 +  "\nTherefore, The Dealer wins.";
				dealerWins++;
				updateHistory(playerCardValueSum, dealerCardValueSum, "dealer");
			}
			
			break;
	}

	labelPlayerObservation->Text = playerName + "'s Hand Value: " + playerCardValueSum;
	labelDealerObservation->Text = "Dealer's Hand Value: " + dealerCardValueSum;

	// Default is true unless one of the statements from switch 6 makes it false
	if (cardWasDealt)
	{
		// Move top card to the bottom of the deck
		CardType table = deck[0];
		for (int i = 1; i <= 51; i++)
			deck[i-1] = deck[i];
		deck[51] = table;
	}

	// Update Stats
	playerLosses = gameNumber - (gameNumber - dealerWins);
	dealerLosses = gameNumber - (gameNumber - playerWins);
	labelPlayerStats->Text = "Wins: " + playerWins 
						   + "\n\nLosses: " + playerLosses;
	labelDealerStats->Text = "Wins: " + dealerWins 
						   + "\n\nLosses: " + dealerLosses;
}

void dealACard(int cardToDeal)
{
	switch(cardToDeal)
	{
		case 1:
			labelPlayerCardValue1->Visible = true;
			labelPlayerCardValue1->Text = deck[0].cardName + " of " + deck[0].cardSuit + " - " + deck[0].cardValue.ToString();
			pictureBoxPlayerCard1->Image = imageListCards->Images[deck[0].cardImageIndex];
			playerCardValueSum += deck[0].cardValue;
			playersHand[0] = deck[0];
			break;

		case 2:
			labelPlayerCardValue2->Visible = true;
			labelPlayerCardValue2->Text = deck[0].cardName + " of " + deck[0].cardSuit + " - " + deck[0].cardValue.ToString();
			pictureBoxPlayerCard2->Image = imageListCards->Images[deck[0].cardImageIndex];
			playerCardValueSum += deck[0].cardValue;
			labelPlayerObservation->Text = playerName + "'s hand value: " + playerCardValueSum.ToString();
			playersHand[1] = deck[0];
			break;

		case 5:
			labelPlayerCardValue3->Visible = true;
			pictureBoxPlayerCard3->Visible = true;
			labelPlayerCardValue3->Text = deck[0].cardName + " of " + deck[0].cardSuit + " - " + deck[0].cardValue.ToString();
			pictureBoxPlayerCard3->Image = imageListCards->Images[deck[0].cardImageIndex];
			playerCardValueSum += deck[0].cardValue;
			labelPlayerObservation->Text = playerName + "'s hand value: " + playerCardValueSum.ToString();
			playersHand[2] = deck[0];
			break;
	}

	// Move top card to the bottom of the deck
	CardType table = deck[0];
	for (int i = 1; i <= 51; i++)
		deck[i-1] = deck[i];
	deck[51] = table;
}

void dealAHand()
{
	dealACard(1);
	dealACard(2);
}

void displayDateTime()
{
	///////////////////////////////////////////////////////
	//				LOCAL VARIABLES/OBJECTS
	///////////////////////////////////////////////////////
	DateTime dateTimeNow = DateTime::Now;
	///////////////////////////////////////////////////////

	labelDateTime->Text = dateTimeNow.ToString();	
}

void displayDeck(array<CardType>^ deck)
{
	///////////////////////////////////////////////////////////////////
	//				LOCAL VARIABLES/OBJECTS
	///////////////////////////////////////////////////////////////////
	String^ theDeck;
	///////////////////////////////////////////////////////////////////
	
	for (int i = 0; i < deck->Length; i++)
	{
		theDeck += i.ToString() + " - " + deck[i].cardName + " of " 
				+ deck[i].cardSuit + " " + deck[i].cardValue + "\n";
	}

	MessageBox::Show(theDeck);
}

bool isMaster(String^ password)
{
	return (password == "master");
}

bool isValidPassword(String^ password)
{
	return (password == "blackjack" || password == "master");
}

void loadDeck()
{
	///////////////////////////////////////////////////////
	//				LOCAL VARIABLES/OBJECTS
	///////////////////////////////////////////////////////
	StreamReader^	sr = gcnew StreamReader("dat/workingDeck.dat");
	String^			line;
	String^			sCardName;
	String^			sCardSuit;
	String^			sCardValue;
	String^			sCardImageIndex;
	String^			fileContents;
	int				spacePos,
					iCardValue,
					iCardImageIndex,
					start,
					subCount,
					subLength;
	///////////////////////////////////////////////////////

	// Read what was in the file
	while ( (line = sr->ReadLine()) != nullptr )
		fileContents += line + "\n";
	sr->Close();
	
	// Report to user what was read from disk
	MessageBox::Show("The following was read from dat/workingDeck.dat\n"
					 + "and this line up will become the new deck:\n\n" + fileContents);

	// Open our file to get ready to read
	sr = gcnew StreamReader("dat/workingDeck.dat");

	// For each card in the deck...
	for (int i = 0; i < deck->Length; i++)
	{
		// Buffer a line from dat/workingDeck.dat
		line = sr->ReadLine();

		// Refresh the variables for this line before parsing
		subLength = 0;
		subCount = 0;
		start = 0;
		spacePos = 0;
		
		// Parses the four elements of one space-delimited line into separate String^ vars
		while ( (start < line->Length) && (subLength > -1) )
		{
			spacePos = line->IndexOf(' ', start);
			subLength = spacePos - start;
			if (subLength == -1)
				break;
			if (subCount == 0)
				sCardValue = line->Substring(start, subLength);
			else if (subCount == 1)
				sCardName = line->Substring(start, subLength);
			else if (subCount == 2)
				sCardSuit = line->Substring(start, subLength);
			else if (subCount == 3)
				sCardImageIndex = line->Substring(start);
			subCount++;
			start = spacePos + 1;
		}

		// Convert the String^ vars into int
		int::TryParse(sCardValue, iCardValue);
		int::TryParse(sCardImageIndex, iCardImageIndex);

		// Merge the card into the working deck
		deck[i].cardValue = iCardValue;
		deck[i].cardName = sCardName;
		deck[i].cardSuit = sCardSuit;
		deck[i].cardImageIndex = iCardImageIndex;
	}

	sr->Close();
}

void setUpDeckByValue()
{
	///////////////////////////////////////////////////////////////////
	//				LOCAL VARIABLES/OBJECTS
	///////////////////////////////////////////////////////////////////
	array<String^>^ suit = {"Clubs", "Diamonds", "Hearts", "Spades"};
	array<String^>^ name = {"Two", "Three", "Four", "Five", "Six", "Seven",
							"Eight","Nine", "Ten", "Jack", "Queen", "King", "Ace"};
	///////////////////////////////////////////////////////////////////

	for (int i = 0; i <= 51; i++)
	{
		if (i >= 48)
			deck[i].cardValue = 11;

		else if (i >= 36)
			deck[i].cardValue = 10;
		
		else
			deck[i].cardValue = i / 4 + 2;

		deck[i].cardName = name[i / 4];
		deck[i].cardSuit = suit[i % 4];
		deck[i].cardImageIndex = i * 905 / 905; // lol
	}
}

void shuffleDeck()
{
	////////////////////////////////////////////////////////////////////////
	//				LOCAL VARIABLES/OBJECTS
	////////////////////////////////////////////////////////////////////////
	String^				stringStationaryCards;
	int					stationaryCount			= 0;
	array<CardType>^	unshuffledDeck			= gcnew array<CardType>(52);
	array<CardType>^	stationaryCards			= gcnew array<CardType>(52);
	////////////////////////////////////////////////////////////////////////

	// Make a copy of the deck before it gets shuffled
	for (int i = 0; i < deck->Length; i++)
		unshuffledDeck[i] = deck[i];

	// Seed the RNG
	srand((int)time(0));

	// Swap card with a card picked from random between 0 and 51
	for (int i = 0; i < deck->Length; i++)
	{
		int randomCard = rand() % 52;
		CardType table = deck[i];
		deck[i] = deck[randomCard];
		deck[randomCard] = table;
	}

	// Find the cards that kept their original positions and copy them to a separate deck
	for (int i = 0; i < deck->Length; i++)
	{
		if (deck[i].cardName == unshuffledDeck[i].cardName)
		{
			if (deck[i].cardSuit == unshuffledDeck[i].cardSuit)
			{
				stationaryCards[stationaryCount] = deck[i];
				stationaryCount++;
			}
		}
	}

	// Display the cards that kept their original positions in a message box
	if (stationaryCount > 0)
	{
		for (int i = 0; i < stationaryCards->Length; i++)
		{
			if (stationaryCards[i].cardValue > 0)  // Don't look at null subvalues
				stringStationaryCards += stationaryCards[i].cardName + " of " + stationaryCards[i].cardSuit + "\n";
		}
		MessageBox::Show(stationaryCount.ToString() + " card(s) remained in the original position before and after the shuffle:\n\n"
						+ stringStationaryCards, "stationaryCards");
	}
	else
		MessageBox::Show("All cards have been shuffled.\n"
			+ "No cards stayed in the same spot after the deck was shuffled.", "No cards in original position");
}

void shuffleDeckPerfect()
{
	////////////////////////////////////////////////////////////////////////
	//				LOCAL VARIABLES/OBJECTS
	////////////////////////////////////////////////////////////////////////
	String^				stringStationaryCards;
	int					stationaryCount			= 0;
	array<CardType>^	unshuffledDeck			= gcnew array<CardType>(52);
	array<CardType>^	stationaryCards			= gcnew array<CardType>(52);
	array<CardType>^	topDeck					= gcnew array<CardType>(26);
	array<CardType>^	bottomDeck				= gcnew array<CardType>(26);
	////////////////////////////////////////////////////////////////////////

	// Make a copy of the deck before it gets shuffled
	for (int i = 0; i < deck->Length; i++)
		unshuffledDeck[i] = deck[i];

	// Cut the deck into half and separate decks
	for (int i = 0; i < topDeck->Length; i++)
		topDeck[i] = deck[i];
	for (int i = 0; i < bottomDeck->Length; i++)
		bottomDeck[i] = deck[i + 26];

	// Interleave both decks evenly
	for (int i = 0; i < deck->Length; i += 2)
		deck[i] = topDeck[i / 2];
	for (int i = 1; i < deck->Length; i += 2)
		deck[i] = bottomDeck[i / 2];

	// Find the cards that kept their original positions and copy them to a separate deck
	for (int i = 0; i < deck->Length; i++)
	{
		if (deck[i].cardName == unshuffledDeck[i].cardName)
		{
			if (deck[i].cardSuit == unshuffledDeck[i].cardSuit)
			{
				stationaryCards[stationaryCount] = deck[i];
				stationaryCount++;
			}
		}
	}

	// Display the cards that kept their original positions in a message box
	if (stationaryCount > 0)
	{
		for (int i = 0; i < stationaryCards->Length; i++)
		{
			if (stationaryCards[i].cardValue > 0)  // Don't look at null subvalues
				stringStationaryCards += stationaryCards[i].cardName + " of " + stationaryCards[i].cardSuit + "\n";
		}
		MessageBox::Show(stationaryCount.ToString() + " card(s) remained in the original position before and after the shuffle:\n\n"
						+ stringStationaryCards, "stationaryCards");
	}
	else
		MessageBox::Show("All cards have been shuffled.\n"
			+ "No cards stayed in the same spot after the deck was shuffled.", "No cards in original position");

}

void storeDeck()
{
	///////////////////////////////////////////////////////
	//				LOCAL VARIABLES/OBJECTS
	///////////////////////////////////////////////////////
	StreamWriter^	sw		= gcnew StreamWriter("dat/workingDeck.dat");
	String^			cardDeck;
	///////////////////////////////////////////////////////

	for (int i = 0; i < deck->Length; i++)
		cardDeck += deck[i].cardValue.ToString() + " " + deck[i].cardName + " " 
				 + deck[i].cardSuit + " " + deck[i].cardImageIndex.ToString() + "\r\n";
	
	sw->WriteLine( cardDeck );
	sw->Close();

	// Report to user what was written to disk
	MessageBox::Show("The following was written to dat/workingDeck.dat\n" + cardDeck, "dat/workingDeck.dat");
}

void updateHistory(int playerSum, int dealerSum, String^ winner)
{
	playersHistory[gameNumber-1].histGameNumber = gameNumber;
	playersHistory[gameNumber-1].histHandTotal = playerSum;
	
	dealersHistory[gameNumber-1].histGameNumber = gameNumber;
	dealersHistory[gameNumber-1].histHandTotal = dealerSum;

	if (winner == "player")
	{
		playersHistory[gameNumber-1].histWinOrLose = "winning";
		dealersHistory[gameNumber-1].histWinOrLose = "losing";
	}

	else if (winner == "dealer")
	{
		playersHistory[gameNumber-1].histWinOrLose = "losing";
		dealersHistory[gameNumber-1].histWinOrLose = "winning";
	}
}

bool verifyAccount(String^ account)
{
	if (account == "1111")
	{
		playerName = "Albert Einstein";
		return true;
	}
	else if (account == "2222")
	{
		playerName = "Madame Curie";
		return true;
	}
	else if (account == "3333")
	{
		playerName = "Johnny B";
		return true;
	}
	else if (account == "4444")
	{
		playerName = "Oscar Peterson";
		return true;
	}
	else if (account == "5555")
	{
		playerName = "Ray Manzarek";
		return true;
	}
	else
		return false;
}

/**************************************************************
***************************************************************
***                                                			***
***			    END NON EVENT-DRIVEN FUNCTIONS				***
***                                                			***
***************************************************************
**************************************************************/

};
}
