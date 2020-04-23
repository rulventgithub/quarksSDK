#include "quarks.h"



void QuarksSDK::CreateWindow::windowSettings(VideoMode mode, const String& title, Uint32 style, const ContextSettings& settings) {




	window = new RenderWindow(mode, title, style, settings);
	x = mode.width;
	y = mode.height;
	if (useDebugLog) {
		cout << "WIINDOW-SIZE: " << x << "," << y << endl;
		cout << "WINDOW-LOCATION: " << window << endl;
		cout << "TITLE-LOCATION: " << &title << endl;

	}
}
bool QuarksSDK::CreateWindow::isWindowOpen()
{
	// before starting gets the player position
	// only if the saving system is true

	if (window->isOpen()) {

		return true;
	}
	else {

		return false;
	}
}
void QuarksSDK::CreateWindow::callDefaultPolls()
{
	if (evnt.type == evnt.Closed) {


		window->close();
	}
	if (evnt.type == evnt.Resized) {

		View tempView;

		// gets aspect ratio
		float aspectRatio = float(window->getSize().x) / float(window->getSize().y);
		tempView.setSize(window->getSize().x * aspectRatio, window->getSize().y);
		window->setView(tempView);
	}

}
void QuarksSDK::CreateWindow::draw(const Drawable& drawable)
{

	window->draw(drawable);
}
void QuarksSDK::CreateWindow::useDeltaTime()
{
	deltaTime = deltaClock.restart().asSeconds();

}
void QuarksSDK::CreateWindow::sdraw(const Drawable& drawable, const RenderStates& states)
{
	window->draw(drawable, states);
}
void QuarksSDK::Movement::addMovement(RectangleShape& obj, float speed)
{
	useDeltaTime();
	if (!noUpUse) {
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			getPosition.y = -speed * deltaTime;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {

			getPosition.y = -speed * deltaTime;
		}
	}
	if (!noDownUse) {
		if (Keyboard::isKeyPressed(Keyboard::S)) {

			getPosition.y = speed * deltaTime;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {

			getPosition.y = speed * deltaTime;
		}
	}
	if (!noleftUse) {

		if (Keyboard::isKeyPressed(Keyboard::Left)) {

			getPosition.x = -speed * deltaTime;
		}


		if (Keyboard::isKeyPressed(Keyboard::A)) {

			getPosition.x = -speed * deltaTime;
		}
	}


	if (!noRightUse) {

		if (Keyboard::isKeyPressed(Keyboard::D)) {
			getPosition.x = speed * deltaTime;
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			getPosition.x = speed * deltaTime;
		}
	}


		



	///
   ///
   ///
	if (!Keyboard::isKeyPressed(Keyboard::W)) {
		up = false;
	}


	if (!Keyboard::isKeyPressed(Keyboard::A)) {
		left = false;
	}



	if (!Keyboard::isKeyPressed(Keyboard::S)) {
		down = false;
	}

	if (!Keyboard::isKeyPressed(Keyboard::D)) {
		right = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		up = true;
	}


	if (Keyboard::isKeyPressed(Keyboard::A)) {
		left = true;
	}



	if (Keyboard::isKeyPressed(Keyboard::S)) {
		down = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		right = true;
	}



	if (!Keyboard::isKeyPressed(Keyboard::Up)) {
		aup = false;
	}


	if (!Keyboard::isKeyPressed(Keyboard::Left)) {
		aleft = false;
	}



	if (!Keyboard::isKeyPressed(Keyboard::Down)) {
		adown = false;
	}

	if (!Keyboard::isKeyPressed(Keyboard::Right
	)) {
		aright = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		aup = true;
	}


	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		aleft = true;
	}



	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		adown = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		aright = true;
	}
	obj.setPosition(obj.getPosition().x + getPosition.x, obj.getPosition().y + getPosition.y);
	getPosition.x = 0; getPosition.y = 0;
}
void QuarksSDK::Movement::SmoothMovement(RectangleShape& obj, float speed, float drag, float maxVelocity, float mutiplier  )
{
	useDeltaTime();
	getPosition.x = 0; getPosition.y = 0;
	if (!noUpUse) {
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			getPosition.y = -1.f;

			if (currentVelocity.y > -maxVelocity)
				currentVelocity.y += speed * getPosition.y * deltaTime * mutiplier;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			getPosition.y = -1.f;

			if (currentVelocity.y > -maxVelocity)
				currentVelocity.y += speed * getPosition.y * deltaTime * mutiplier;
		}
	}
	if (!noDownUse) {
	
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			getPosition.y = 1.f;

			if (currentVelocity.y < maxVelocity)
				currentVelocity.y += speed * getPosition.y * deltaTime * mutiplier;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			getPosition.y = 1.f;

			if (currentVelocity.y < maxVelocity)
				currentVelocity.y += speed * getPosition.y * deltaTime * mutiplier;
		}

	}
	if (!noleftUse) {


		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			getPosition.x = -1.f;

			if (currentVelocity.x > -maxVelocity)
				currentVelocity.x += speed * getPosition.x * deltaTime * mutiplier;
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			getPosition.x = -1.f;

			if (currentVelocity.x > -maxVelocity)
				currentVelocity.x += speed * getPosition.x * deltaTime * mutiplier;
		}
	
	}


	if (!noRightUse) {


		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			getPosition.x = 1.f;

			if (currentVelocity.x < maxVelocity)
				currentVelocity.x += speed * getPosition.x * deltaTime * mutiplier;
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			getPosition.x = 1.f;

			if (currentVelocity.x < maxVelocity)
				currentVelocity.x += speed * getPosition.x * deltaTime * mutiplier;
		}

	}
		
	
	
	
 



	if (!Keyboard::isKeyPressed(Keyboard::W)) {
		up = false;
	}


	if (!Keyboard::isKeyPressed(Keyboard::A)) {
		left = false;
	}



	if (!Keyboard::isKeyPressed(Keyboard::S)) {
		down = false;
	}

	if (!Keyboard::isKeyPressed(Keyboard::D)) {
		right = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		up = true;
	}


	if (Keyboard::isKeyPressed(Keyboard::A)) {
		left = true;
	}



	if (Keyboard::isKeyPressed(Keyboard::S)) {
		down = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		right = true;
	}




	if (!Keyboard::isKeyPressed(Keyboard::Up)) {
		aup = false;
	}


	if (!Keyboard::isKeyPressed(Keyboard::Left)) {
		aleft = false;
	}



	if (!Keyboard::isKeyPressed(Keyboard::Down)) {
		adown = false;
	}

	if (!Keyboard::isKeyPressed(Keyboard::Right
	)) {
		aright = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		aup = true;
	}


	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		aleft = true;
	}



	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		adown = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		aright = true;
	}
	// drag
	if (currentVelocity.x > 0.f) {
		currentVelocity.x -= drag * deltaTime * mutiplier;
		if (currentVelocity.x < 0.f) {
			currentVelocity.x = 0.f;

		}

	}
	else if (currentVelocity.x < 0.f) {
		currentVelocity.x += drag * deltaTime * mutiplier;
		if (currentVelocity.x > 0.f) {
			currentVelocity.x = 0.f;

		}

	}


	if (currentVelocity.y > 0.f) {
		currentVelocity.y -= drag * deltaTime * mutiplier;
		if (currentVelocity.y < 0.f) {
			currentVelocity.y = 0.f;

		}

	}
	else if (currentVelocity.y < 0.f) {
		currentVelocity.y += drag * deltaTime * mutiplier;
		if (currentVelocity.y > 0.f) {
			currentVelocity.y = 0.f;

		}

	}
	obj.move(currentVelocity.x * deltaTime * mutiplier, currentVelocity.y * deltaTime * mutiplier);
}
QuarksSDK::Collision::Collision()
{
}
void QuarksSDK::Collision::PCollision(RectangleShape& _Give, RectangleShape& _Obtain)
{
	FloatRect playerbounds = _Give.getGlobalBounds();
	FloatRect wallbounds = _Obtain.getGlobalBounds();
	 
	nextpos = playerbounds;
	nextpos.left += getPosition.x;
	nextpos.top += getPosition.y;
	if (nextpos.intersects(wallbounds)) {

		// bottom 
		if (playerbounds.top < wallbounds.top &&
			playerbounds.top + playerbounds.height < wallbounds.top + wallbounds.height &&
			playerbounds.left < wallbounds.left + wallbounds.width &&
			playerbounds.left + playerbounds.width> wallbounds.left) {
			getPosition.y = 0.f;
			_Give.setPosition(playerbounds.left, wallbounds.top - playerbounds.height);

		}
		else if (playerbounds.top > wallbounds.top&&
			playerbounds.top + playerbounds.height > wallbounds.top + wallbounds.height &&
			playerbounds.left < wallbounds.left + wallbounds.width &&
			playerbounds.left + playerbounds.width> wallbounds.left) {
			getPosition.y = 0.f;
			_Give.setPosition(playerbounds.left, wallbounds.top + wallbounds.height);

		}


		else if (playerbounds.left < wallbounds.left &&
			playerbounds.left + playerbounds.width < wallbounds.left + wallbounds.width &&
			playerbounds.top < wallbounds.top + wallbounds.height &&
			playerbounds.top + playerbounds.height > wallbounds.top) {
			getPosition.x = 0.f;
			_Give.setPosition(wallbounds.left - playerbounds.width, playerbounds.top);
		}

		else if (playerbounds.left > wallbounds.left&&
			playerbounds.left + playerbounds.width > wallbounds.left + wallbounds.width &&
			playerbounds.top < wallbounds.top + wallbounds.height &&
			playerbounds.top + playerbounds.height > wallbounds.top) {
			getPosition.x = 0.f;
			_Give.setPosition(wallbounds.left + wallbounds.width, playerbounds.top);
		}



	}


}
void QuarksSDK::Collision::collision(RectangleShape& _Give, RectangleShape& _Obtain, float _Push)
{

	sf::Vector2f otherposition = _Give.getPosition();
	Vector2f otherHalfSize = _Give.getSize() / 2.0f;
	sf::Vector2f thisposition = _Obtain.getPosition();
	Vector2f thisHalfSize = _Obtain.getSize() / 2.0f;

	float deltaX = otherposition.x - thisposition.x;
	float deltaY = otherposition.y - thisposition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {

		_Push = std::min(std::max(_Push, 0.0f), 1.0f);
		if (intersectX > intersectY) {
			if (deltaX > 0.0f) {
				_Obtain.move(intersectX * (1.0 - _Push), 0.0f);
				_Give.move(-intersectX * _Push, 0.0f);
			}
			else {
				_Obtain.move(-intersectX * (1.0 - _Push), 0.0f);
				_Give.move(intersectX * _Push, 0.0f);
			}

		}
		else {

			if (deltaY > 0.0f) {
				_Obtain.move(0.0f, intersectY * (1.0 - _Push));
				_Give.move(0.0f, -intersectY * _Push);
			}
			else {
				_Obtain.move(0.0f, -intersectY * (1.0 - _Push));
				_Give.move(0.0f, intersectY * _Push);
			}

		}

	}
}
void QuarksSDK::Collision::platformCollision(RectangleShape& _Give, RectangleShape& _Obtain) {
	FloatRect playerbounds = _Give.getGlobalBounds();
	FloatRect wallbounds = _Obtain.getGlobalBounds();
	nextpos = playerbounds;
	nextpos.left += getPosition.x;
	nextpos.top += getPosition.y;
	if (nextpos.intersects(wallbounds)) {

		// bottom 
		if (playerbounds.top < wallbounds.top &&
			playerbounds.top + playerbounds.height < wallbounds.top + wallbounds.height &&
			playerbounds.left < wallbounds.left + wallbounds.width &&
			playerbounds.left + playerbounds.width> wallbounds.left) {
			getPosition.y = 0.f;
			_Give.setPosition(playerbounds.left, wallbounds.top - playerbounds.height);

		}



	}




}
void QuarksSDK::Collision::screenCollision(RectangleShape& _Give, QuarksSDK::CreateWindow& window)
{
	// left col
	if (_Give.getPosition().x < 0) {

		_Give.setPosition(0, _Give.getPosition().y);
	}
	// top col 
	if (_Give.getPosition().y < 0) {

		_Give.setPosition(_Give.getPosition().x, 0);
	}
	// Right col
	if (_Give.getPosition().x + _Give.getGlobalBounds().width > window.getSize().x) {

		_Give.setPosition(window.getSize().x - _Give.getGlobalBounds().width, _Give.getPosition().y);
	}


	// bottom col
	if (_Give.getPosition().y + _Give.getGlobalBounds().height > window.getSize().y) {

		_Give.setPosition(_Give.getPosition().x, window.getSize().y - _Give.getGlobalBounds().height);
	}
}
QuarksSDK::Animation::Animation(Texture* texture, Vector2u imagecount, float switchTime) {

	this->switchTime = switchTime;
	this->imagecount = imagecount;
	totalTime = 0.0f;
	currentimage.x = 0;

	// calculate height and width
	uvrect.width = texture->getSize().x / float(imagecount.x);
	uvrect.height = texture->getSize().y / float(imagecount.y);

}
void QuarksSDK::Animation::update(int row, float deltatime, bool faceRight) {
	currentimage.y = row;
	totalTime += deltatime;

	if (totalTime >= switchTime/*the time given to switch the frame*/) {
		totalTime -= switchTime; // smoother animation
		currentimage.x++; // switches the current image we have ex 0- > 1 x

		if (currentimage.x >= imagecount.x) {
			currentimage.x = 0; // if it's heigher then the amount we have in total, it will return back to 0.

		}

	}


	uvrect.top = currentimage.y * uvrect.height;

	if (faceRight) {
		uvrect.left = currentimage.x * uvrect.width;

		uvrect.width = abs(uvrect.width);

	}
	else {

		uvrect.left = (currentimage.x + 1) * abs(uvrect.width);
		uvrect.width = -abs(uvrect.width);
	}



}
Vector2f QuarksSDK::Normilize(Vector2f x)
{



	float _fan = sqrt(pow(x.x, 2) + pow(x.y, 2));
	Vector2f temp(x.x, x.y);
	Vector2f foo(temp.x / _fan, temp.y / _fan);

	return foo;
}
nQuarks::TCP::TCP(const std::string& _Ip, unsigned short _Port)
{


	this->_Ip == _Ip;
	this->_Port = _Port;

}
void nQuarks::TCP::send(Packet& packet)
{
	listener.listen(_Port);
	listener.accept(Socket);
	Socket.send(packet);


}
void nQuarks::TCP::send(const void* packet, size_t size)
{
	this->size = size;
	this->packet = packet;


	listener.listen(_Port);
	listener.accept(Socket);
	Socket.send(packet, size);


}
void nQuarks::TCP::dcsend(Packet& packet)
{
	listener.listen(_Port);
	listener.accept(Socket);
	Socket.send(packet);


}
void nQuarks::TCP::dcsend(const void* packet, size_t size)
{
	this->size = size;
	this->packet = packet;



	Socket.send(packet, size);


}
void nQuarks::TCP::receive()
{


	Socket.connect(_Ip, _Port);
	Socket.receive(buffer, sizeof(buffer), received);


}
void nQuarks::TCP::receive(Packet& packet)
{


	Socket.connect(_Ip, _Port);
	Socket.receive(packet);


}
void nQuarks::TCP::dcreceive()
{


	Socket.receive(buffer, sizeof(buffer), received);


}
void nQuarks::TCP::dcreceive(Packet& packet)
{


	Socket.receive(packet);


}
void guiQuarks::Button::createButton(Vector2f size, Vector2f positions, Color _Color)
{

	button.setFillColor(_Color);
	_color = _Color;
	button.setPosition(positions);
	button.setSize(size);
	button.setOrigin(Vector2f(size.x / 2, size.y / 2));

}
void guiQuarks::Button::useBtn(CreateWindow windowContext)
{
	windowContext.setDefaultViewPosition();
	windowContext.setView();

	if (button.getGlobalBounds().contains(windowContext.window->mapPixelToCoords(Mouse::getPosition(*windowContext.window)))) {
		Color temp;
		temp = _color;
		temp.r = _color.r + 1;
		temp.g = _color.g - 20;
		temp.b = _color.b - 46;
		button.setFillColor(temp);
		if (Mouse::isButtonPressed(Mouse::Left)) {

			temp = _color;
			temp.r = _color.r + 1;
			temp.g = _color.g - 20 + 10;
			temp.b = _color.b - 46 + 10;
			button.setFillColor(temp);
			isPressed = true;
		}
		else {
			isPressed = false;
		}

	}
	else {
		isPressed = false;

		button.setFillColor(Color(_color.r, _color.g, _color.b));

	}
	windowContext.draw(button);

}
void guiQuarks::LabelButton::createButton(string font, string Text, int _tSize, Vector2f size, Vector2f positions, Color _Color)
{
	button.setFillColor(_Color);
	_color = _Color;
	button.setPosition(positions);
	button.setSize(size);
	button.setOrigin(Vector2f(button.getGlobalBounds().width / 2, button.getGlobalBounds().height / 2));



	this->font.loadFromFile(font);
	text.setFont(this->font);
	text.setCharacterSize(_tSize);
	text.setString(Text);

	text.setPosition(
		(button.getPosition().x + (button.getGlobalBounds().width / 2.f) - text.getGlobalBounds().width / 2.f) - 100,
		(button.getPosition().y + (button.getGlobalBounds().height / 2.f) - text.getGlobalBounds().height / 2.f) - 30

	);
}
void guiQuarks::LabelButton::useBtn(CreateWindow windowContext)
{
	windowContext.setDefaultViewPosition();
	windowContext.setView();


	if (button.getGlobalBounds().contains(windowContext.window->mapPixelToCoords(Mouse::getPosition(*windowContext.window)))) {
		Color temp;
		temp = _color;
		temp.r = _color.r + 1;
		temp.g = _color.g - 20;
		temp.b = _color.b - 46;
		button.setFillColor(temp);
		if (Mouse::isButtonPressed(Mouse::Left)) {

			text.setPosition(
				(button.getPosition().x + (button.getGlobalBounds().width / 2.f) - text.getGlobalBounds().width / 2.f) - 100,
				(button.getPosition().y + (button.getGlobalBounds().height / 2.f) - text.getGlobalBounds().height / 2.f) - 30

			);

			temp = _color;
			temp.r = _color.r + 1;
			temp.g = _color.g - 20 + 10;
			temp.b = _color.b - 46 + 10;
			button.setFillColor(temp);
			isPressed = true;
		}
		else {
			isPressed = false;
		}

	}
	else {
		isPressed = false;

		button.setFillColor(Color(_color.r, _color.g, _color.b));

	}
	windowContext.draw(button);
	windowContext.draw(text);
}
void guiQuarks::Dialog::createDialog(string font, string Text, int _tSize, Vector2f size, Vector2f positions, Color _Color)
{
	button.setFillColor(_Color);
	_color = _Color;
	button.setPosition(positions);
	button.setSize(size);
	button.setOrigin(Vector2f(button.getGlobalBounds().width / 2, button.getGlobalBounds().height / 2));
	


	this->font.loadFromFile(font);
	text.setFont(this->font);
	text.setCharacterSize(_tSize);
	text.setString(Text);
	text.setPosition(
		(button.getPosition().x + (button.getGlobalBounds().width / 2.f) - text.getGlobalBounds().width / 2.f) - 100,
		(button.getPosition().y + (button.getGlobalBounds().height / 2.f) - text.getGlobalBounds().height / 2.f) - 30

	);
}
bool guiQuarks::Dialog::useDialog(CreateWindow windowContext, float duration)
{
	windowContext.setDefaultViewPosition();
	windowContext.setView();

	if (clk.getElapsedTime().asSeconds() < duration) {




		windowContext.draw(button);
		windowContext.draw(text);
		return true;
	}
	else {
		return false;
	}

}
void guiQuarks::TextBox::createTextBox(string font,bool useLineSpace, int charSize, Color color ,bool useLimit, int textLimit, Vector2f pos)
{
 	 
	this->useLineSpace = useLineSpace;

	this->font.loadFromFile(font);
	text.setFont(this->font);
	text.setCharacterSize(charSize);
	text.setFillColor(color);
	text.setPosition(
		pos

	);
	LimitActive == useLimit;
	this->limit = textLimit;

}
void guiQuarks::TextBox::inputLogic(int charTyped)
{
	if (charTyped != deleteKey && charTyped != enterKey) {
	
			ttext << static_cast<char>(charTyped);
		
	} else if (charTyped == deleteKey) {

		if (ttext.str().length() != 0) {
		deleteLastCharacter();
	}
	}
	else if (charTyped == 13 && useLineSpace) {
 
		std::string t = ttext.str();
		std::string newT = "\n";
	 
		
		ttext << newT;
		
	}
	text.setString(ttext.str() + cursor);
}
void guiQuarks::TextBox::deleteLastCharacter()
{
	std::string t = ttext.str();
	std::string newT = "" ;
	for (int i = 0; i < t.length() - 1; i++) {
		newT += t[i];
	}
	ttext.str("");
	ttext << newT;
	text.setString(ttext.str() + cursor );
}
QuarksAnimator::BlockAnimation::BlockAnimation(RectangleShape& _Obj)
{
	ptemp = _Obj.getPosition();
	stemp = _Obj.getSize();
}
bool QuarksAnimator::BlockAnimation::changePosupdate(float dur , RectangleShape& _Obj, float incrementBy, Vector2f endPos)
{
	if (clock.getElapsedTime().asSeconds() > dur) {
		
		if (_Obj.getPosition() == endPos)
		{ 
			_Obj.setPosition(ptemp);
			return true;
		}
		else {
			if (endPos.x != 0) {
				_Obj.move(QuarksSDK::Normilize(Vector2f(_Obj.getPosition().x + incrementBy, _Obj.getPosition().y)));
			}
			if (endPos.y != 0) {
				_Obj.move(QuarksSDK::Normilize(Vector2f(_Obj.getPosition().x, _Obj.getPosition().y+ incrementBy)));
			}
		}
		clock.restart();
	}
	return false;
	
}
bool QuarksAnimator::BlockAnimation::subPosupdate(float dur, RectangleShape& _Obj, float incrementBy, Vector2f endPos)
{
 	if (clock.getElapsedTime().asSeconds() > dur) {

		if (_Obj.getPosition() == endPos)
		{
			_Obj.setPosition(ptemp);
			return true;
		}
		else {
			if (endPos.x != 0) {
				_Obj.move(QuarksSDK::Normilize(Vector2f(_Obj.getPosition().x - incrementBy, _Obj.getPosition().y)));
			}
			if (endPos.y != 0) {
				_Obj.move(QuarksSDK::Normilize(Vector2f(_Obj.getPosition().x, _Obj.getPosition().y- incrementBy)));
			}
		}
		clock.restart();
	}
	return false;

}
void QuarksAnimator::BlockAnimation::changeSizeUpdate(float dur, RectangleShape& _Obj, float incrementBy, Vector2f size)
{
	if (clock.getElapsedTime().asSeconds() > dur) {

		if (_Obj.getSize() == ptemp)
		{
			_Obj.setSize(ptemp);
 		}
		else {
			if (_Obj.getSize().x != size.x) {
				_Obj.setSize(Vector2f(_Obj.getSize().x + incrementBy, _Obj.getSize().y));
			}
			if (_Obj.getSize().y != size.y) {
				_Obj.setSize(Vector2f(_Obj.getSize().x, _Obj.getSize().y + incrementBy));
			}
		}
		clock.restart();
	}

}
