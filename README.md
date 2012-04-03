Using PlacePlay Leaderboards in Unity
=====================================

PlacePlay Leaderboards are the simplest way to meet Apple's location-based feature requirement to serve location-targeted banner ads. Just submit each player's score to the PlacePlay server and give them a button where they can see how they rank against other players in their city, state or country. It's fully compatible with other leaderboard solutions like GameCenter and OpenFeint, but goes places those guys fear to tread.

Follow the instructions below to add it to your Unity project. You can also check out our sample project by selecting Open Project, then the "Unity Ads" folder.

Register Your Game
------------------

1. Go to [PlacePlay.com](http://placeplay.com) to signup for the PlacePlay service.
2. We'll send you back a Game ID, Game Secret and Leaderboard ID.

Add Plugin to Your Unity Project
--------------------------------
1. Drag and drop LeaderboardScript.cs and the Plugins folder onto your Project tab

2. Drag and drop LeaderboardScript on the required component (ex. Main Camera)

3. Open the Inspector for the component used above and set the following parameters in the "Leaderboard Script (Script)" section.

	* Server Link --> PP_SERVER / PP_DEV_SERVER (PlacePlay Servers)
	* Game ID --> Received after sign up
	* Game Secret Key --> Received after sign up
	* Location Getting Purpose --> A string value regarding why the location is being used (ex. Share location to compete locally)
	* Leaderboard ID --> Received after sign up

Setup New User
--------------
1. Create an instance of LeaderboardScript.cs file. 

	LeaderboardScript leaderboardScript = new LeaderboardScript();

2. Call setUser method and pass user name as an argument. 
	
	leaderboardScript.setUser("user name");

Post Score to Leaderboard
-------------------------
1. Create an instance of LeaderboardScript.cs file. 

	LeaderboardScript leaderboardScript = new LeaderboardScript();

2. Call postScore method and pass game score as an argument. 

	leaderboardScript.postScore("1000");

You are done!!!

Known Issues
------------
Sometimes the XCode project generated from Unity fail to include MapKit Framework. Please add it manually if its not there.

