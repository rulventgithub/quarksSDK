#define deleteKey 8
#define enterKey 13
// c++:
#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <sstream>
/*
quarksSDK| sfml engine

*/
using namespace std; using namespace sf;
#define PI 3.1415926535897 
namespace QuarksSDK {
	class CreateWindow
	{
	public:


		void windowSettings(VideoMode mode, const String& title, Uint32 style = Style::Default, const ContextSettings& settings = ContextSettings());
		bool isWindowOpen();
		bool windowPollevents() {
			return window->pollEvent(evnt);
		}
		void callDefaultPolls();
		Event evnt;

		View getView() { return view; };
		void draw(const Drawable& drawable);
		void clear(Color color = Color::Black) { window->clear(color); };
		void display() { window->display(); };
		void useDeltaTime();
		void sdraw(const Drawable& drawable, const RenderStates& states = RenderStates::Default);
		void exit() { window->close(); }
		RenderWindow* window;
		void setViewPosition(Vector2f center) {
			view.setSize(window->getDefaultView().getSize());

			view.setCenter(center);
			window->setView(view);

		}
		void setViewPosition(float x, float y) {

			view.setSize(window->getDefaultView().getSize());

			view.setCenter(x, y);
			window->setView(view);

		}
		void setDefaultViewPosition() {
			view = window->getDefaultView();

		}
		void setView() {
			window->setView(view);

		}
		Vector2f getSize() {
			return Vector2f(x, y);

		}
		float deltaTime = 0;
		float x, y;
		bool useDebugLog = false;

	private:
		View view;
		RectangleShape obj;
		Clock deltaClock;
	};

	/*
	Movement
	=-=-=-=-

	*/
	class Movement : CreateWindow{

	public:
		void addMovement(RectangleShape& obj  , float speed );
		void SmoothMovement(RectangleShape& obj,  float speed = 0.9, float drag = 0.5f, float maxVelocity = 14.f, float mutiplier = 60.f );
		bool checkKeyPressed(Keyboard::Key _Key) {
			if (Keyboard::isKeyPressed(_Key)) {
				return true;

			}
			else {
				return false;
			}
		}
		Vector2f getPosition;
		Vector2f currentVelocity;
		bool left;
		bool right;
		bool up;
		bool down;

		bool aleft;
		bool aright;
		bool aup;
		bool adown;

		// booleans
		bool noleftUse = false;
		bool noRightUse = false;
		bool noUpUse = false;
		bool noDownUse = false;
	private:
	};



	class Collision :  CreateWindow, Movement {
	public:
		Collision();
		void PCollision(RectangleShape& _Give, RectangleShape& _Obtain);
		void collision(RectangleShape& _Give, RectangleShape& _Obtain, float _Push);
		void platformCollision(RectangleShape& _Give, RectangleShape& _Obtain);
		void screenCollision(RectangleShape& _Give, CreateWindow& window);

	public:

		FloatRect nextpos;
	};
	class Animation
	{
	public:
		Animation(Texture* texture, Vector2u imagecount, float switchTime);
		void update(int row, float deltatime, bool faceRight);
		IntRect uvrect;

	private:
		Vector2u imagecount;
		Vector2u currentimage;

		float totalTime;
		float switchTime;

	};

	Vector2f Normilize(Vector2f x);







}
namespace QuarksAnimator {

	class BlockAnimation
	{
	public:
		BlockAnimation(RectangleShape& _Obj);
		bool changePosupdate(float dur , RectangleShape& _Obj , float incrementBy ,Vector2f endPos);
		void changeSizeUpdate(float dur, RectangleShape& _Obj, float incrementBy, Vector2f size);
		bool subPosupdate(float dur, RectangleShape& _Obj, float incrementBy, Vector2f size);


	private:
		Clock clock;
		Vector2f ptemp;
		Vector2f stemp;
	};

	// general infomations :D
	// t = time;
	// b = start value!;
	// c =change in value;
	// d = duration;
	// hope you enjoy this tweening!
	// the algro is from http://gizma.com/easing/#l
	// end
	class easeQuarks {
	public:
		float linear(float t, float b, float  c, float d) {
			return static_cast<float>(c * (t / d) + b);

		}
		float easeInQuad(float t, float b, float  c, float d) {
			t /= d;
			return static_cast<float>(-c * t * (t - 2) + b);
		}
		float  easeInOutQuad(float t, float b, float  c, float d) {
			t /= d / 2;
			if (t < 1) {
				return static_cast<float>(c / 2 * t * t + b);
			}
			t--;
			return static_cast<float>(-c / 2 * (t * (t - 2) - 1) + b);
		}
		float easeInCubic(float t, float b, float  c, float d) {
			t /= d;
			return static_cast<float>(c * t * t * t + b);
		}
		float easingOut(float t, float b, float  c, float d) {
			t /= d;
			t--;
			return static_cast<float>(c * (t * t * t + 1) + b);
		}
		float easingInOutCubic(float t, float b, float  c, float d) {
			t /= d / 2;
			if (t < 1) {
				return static_cast<float>(c / 2 * t * t * t + b);
			}
			t -= 2;
			return static_cast<float>(c / 2 * (t * t * t + 2) + b);
		}
		float easeInQuart(float t, float b, float  c, float d) {
			t /= d;
			return static_cast<float>(c * t * t * t * t + b);
		}
		float easeOutQuart(float t, float b, float  c, float d) {
			t /= d;
			t--;
			return static_cast<float>(-c * (t * t * t * t - 1) + b);
		}
		float easeInOutQuart(float t, float b, float  c, float d) {
			t /= d / 2;
			if (t < 1) {

				return static_cast<float>(c / 2 * t * t * t * t + b);
			}
			t -= 2;
			return static_cast<float>(-c / 2 * (t * t * t * t - 2) + b);
		}

		float easeInSine(float t, float b, float  c, float d) {
			return  static_cast<float>(-c * cos(t / d * (PI / 2)) + c + b);
		}

		float easeInOutSine(float t, float b, float  c, float d)
		{
			return static_cast<float>(-c / 2 * (cos(PI * t / d) - 1) + b);

		}
		float easeInExpo(float t, float b, float  c, float d)
		{
			return static_cast<float>(c * pow(2, 10 * (t / d - 1)) + b);
		}
		float easeOutExpo(float t, float b, float  c, float d)
		{
			return static_cast<float>(c * (-pow(2, -10 * t / d) + 1) + b);
		}
		float easeInOutExpo(float t, float b, float  c, float d)
		{
			t /= d / 2;
			if (t < 1) {
				return static_cast<float>(c / 2 * pow(2, 10 * (t - 1)) + b);
			}
			t--;
			return static_cast<float>(c / 2 * (-pow(2, -10 * t) + 2) + b);
		}
		// /////////////////////////////
		// circles
		// /////////////////////////////
		float easeInCirc(float t, float b, float  c, float d)
		{


			t /= d;
			return -c * (sqrt(1 - t * t) - 1) + b;
		};
		float easeOutCirc(float t, float b, float  c, float d) {
			t /= d;
			t--;
			return static_cast<float>(c * sqrt(1 - t * t) + b);

		}
		float easeInOutCirc(float t, float b, float  c, float d) {

			if (t < 1) return -c / 2 * (sqrt(1 - t * t) - 1) + b;
			t -= 2;
			return static_cast<float>(c / 2 * (sqrt(1 - t * t) + 1) + b);
		}

	};
}
namespace guiQuarks {

	class Button : QuarksSDK::CreateWindow {
	public:

		void createButton(Vector2f size = Vector2f(200, 50), Vector2f positions = Vector2f(0, 0), Color _Color = Color(0, 104, 224));
		void useBtn(CreateWindow windowContext);
		RectangleShape button;
		bool isPressed = false;
	private:
		Color _color;
	};

	class LabelButton : QuarksSDK::CreateWindow {
	public:

		void createButton(string font, string Text = "newBtn", int _tSize = 12, Vector2f size = Vector2f(200, 50), Vector2f positions = Vector2f(0, 0), Color _Color = Color(0, 104, 224));
		void useBtn(CreateWindow windowContext);
		void setLabel(string text) { this->text.setString(text); };
		RectangleShape button;
		bool isPressed = false;
	private:
		Color _color;
		Text text;
		Font font;
		float x;
		float y;
	};
	class Dialog : QuarksSDK::CreateWindow {
	public:
		void createDialog(string font, string Text = "newBtn", int _tSize = 12, Vector2f size = Vector2f(200, 50), Vector2f positions = Vector2f(0, 0), Color _Color = Color(0, 104, 224));
		bool useDialog(CreateWindow windowContext, float duration);
		void reset() { clk.restart(); };
		void setLabel(string text) { this->text.setString(text); };
		RectangleShape button;
		bool isPressed = false;
		Text text;
	private:
		Color _color;
		Font font;
		float x;
		float y;
		Clock clk;

	};
	class TextBox : QuarksSDK::CreateWindow {
	public:

		void createTextBox(string font, bool useLineSpace= true, int charSize=30 , Color color = Color::White ,bool useLimit = false,int textLimit=100 , Vector2f pos = Vector2f(0,0));
		void useTextBox(CreateWindow windowContext) { windowContext.draw(text); };
		void clearString() {
			ttext.str("");
			text.setString("");
};
		void EventText(Event evnt) {
			int charTyped = evnt.text.unicode;
			if (charTyped < 128) {
				if (LimitActive) {
					if (ttext.str().length() <= limit) {

						inputLogic(charTyped);
					}
					else {
						if (ttext.str().length() > limit) {

							if (charTyped == deleteKey) {
								deleteLastCharacter();

							}
						}
					}
				}
				else  if (!LimitActive)
				{
					inputLogic(charTyped);

				}
			}
		}
		string getText(){
			return ttext.str();
		}
		char cursor = '_';
	private:
		ostringstream ttext;
		bool useLineSpace = false;
		Color _color;
		Text text;
		Font font;
		float x;
		float y;
		int limit = 0;
		bool LimitActive = false;
		void inputLogic(int charTyped);
		void deleteLastCharacter();

	};
	class giveButtonCharacteristics : QuarksSDK::CreateWindow{
	public:
		void giveObjectButtonCharacteristic(RectangleShape& _give, QuarksSDK::CreateWindow& window_context ) {
			if (_give.getGlobalBounds().contains(window_context.window->mapPixelToCoords(Mouse::getPosition(*window_context.window)))) {
				
				isHovering = true;
				if (Mouse::isButtonPressed(Mouse::Left)) {
					isLeft = true;

				}
				else if (Mouse::isButtonPressed(Mouse::Right)) {
					isRight = true;

				}
				else {
					isLeft = false;
					isRight = false;
				}
			}
			else {
				isHovering = false;
			}

		}
		bool isLeft = false;
		bool isHovering = false;
		bool isRight = false;
	private:


	};
};
namespace nQuarks {

	class TCP
	{
	public:
		TCP(const std::string& _Ip, unsigned short _Port = 2000);
		void send(Packet& packet);
		void send(const void* packet, size_t size);
		void dcsend(Packet& packet);
		void dcsend(const void* packet, size_t size);

		//rev
		void receive();
		void receive(Packet& packet);
		void setBlocking(bool blockSTATUS) { Socket.setBlocking(blockSTATUS); };
		void dcreceive();
		void dcreceive(Packet& packet);
		void Listen() {
			listener.listen(_Port);
			listener.accept(Socket);

		}
		void Connect() {

			Socket.connect(_Ip, _Port);
		}
		char buffer[2000];
		void usePublic() {
			_Ip = IpAddress::getPublicAddress();

		}
		TcpSocket Socket;
		size_t received;
	private:
		TcpListener listener;
		const void* packet;
		size_t size;

		IpAddress _Ip = IpAddress::getLocalAddress();
		unsigned short _Port = 2000;
	};

	
	class UDP {

	public:

		UDP(const std::string& _Ipp, unsigned short _Port = 2000) : _Ip(_Ipp), port(_Port) {};

		void usePublic() {
			_Ip = IpAddress::getPublicAddress();

		}

		// similar to TCP, it is listening for anyhting that is on the port.
		void bindsPort() {

			socket.bind(port);
		}

		;
		void setBlocket(bool _Value) { socket.setBlocking(_Value); };

		void recive() {
			IpAddress _rIp;
			unsigned short rport;
			socket.receive(buffer, sizeof(buffer), received, _rIp, rport);
			if (received > 0) {
				computerID[port] = _rIp;

			}
		}
	private:
		UdpSocket _UDP;
		IpAddress _Ip = IpAddress::getLocalAddress();
		UdpSocket socket;
		char buffer[2000];
		size_t received;
		unsigned short port = 2000;
		map<unsigned short, sf::IpAddress> computerID;
	};
};
 


 