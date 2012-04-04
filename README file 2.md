# How to Add PlacePlay Ads to Your Android App

Follow these instructions to integrate PlacePlay Ads in your Android app. You can use PlacePlay Ads on its own or integrated with an ad mediation solution such as AdWhirl. AdWhirl-specific instructions are included below. Contact us if you need help using PlacePlay Ads with other ad mediation platforms.

## Installation

1. Go to http://placeplay.com/ads to signup for the PlacePlay Ads service and get an AppID. (If you’ve already integrated PlacePlay, this is your Game ID.)

2. Clone/Download SDK from GitHub

3. Add the following value as metadata in your application (Alternately you can pass the app id everytime you create the PALayout)
	
		Meta data Name: PLACEPLAY_GAMEID
		Meta data value: <YOUR APP ID HERE>

4. Use the following Android permissions:
		
		android.permission.ACCESS_COARSE_LOCATION
		android.permission.ACCESS_FINE_LOCATION
		android.permission.READ_PHONE_STATE
		android.permission.INTERNET
		android.permission.ACCESS_NETWORK_STATE

5. Add PAAdBrowser activity defined in the SDK to the activity list in the project's AndroidManifest.xml

6. Call the following methods to display an ad:

		int diWidth = 320; // These values are best display values but can be changed
		int diHeight = 50; // according to necessity.
		float density = getResources().getDisplayMetrics().density;

		adLayout = (PALayout)findViewById(R.id.pa_ad_layout); //if layout set in activity's layout
		//adLayout = new PALayout(this, <your app id>); //Alternate way to instantiate. Layout params need to be set and added to content. pass app id as null if meta data already added.
		
		adLayout.setMaxWidth((int)(diWidth * density));
		adLayout.setMaxHeight((int)(diHeight * density));

		//Request the ad
		adLayout.requestAd(true); // Set true for repeating the request process. For single time ad request set it to false

7. Optionally you can implement PAAdListener also

		//Optional
		adLayout.setPAAdListener((com.placeplay.ads.PAAdListener)this)

		public void pA_RequestAdSuccess() {
			//on Ad being received and displayed successfully
		}
	
		public void pA_RequestAdFail() {
			//on Ad request failure
		}

8. Stop the request service when not required anymore by adding the following code.

		if (adLayout != null) {
			adLayout.stopAdService();
		}

## AdWhirl Integration

Follow these steps to use PlacePlayAds with AdWhirl to manage multiple banner ad networks.

1. Use the AdWhirl library project provided in the External/ of the package to use our Quattro fix for full integration of PlacePlayAds with AdWhirl

2. Set up AdWhirl SDK key as meta data in the application manifest (Alternately you can pass the sdk key every time you create the AdWhirlLayout).

		Meta data Name: ADWHIRL_KEY
		Meta data value: <YOUR APP'S ADWHIRL SDK KEY HERE>
			
3. Call the following methods for AdWhirl:

		int diWidth = 320; // These values are best display values but can be changed
		int diHeight = 50; // according to necessity.
		float density = getResources().getDisplayMetrics().density;
		
		AdWhirlManager.setConfigExpireTimeout(1000 * 60 * 5);

		AdWhirlTargeting.setAge(23);
		AdWhirlTargeting.setGender(AdWhirlTargeting.Gender.MALE);
		AdWhirlTargeting.setKeywords("online games gaming");
		AdWhirlTargeting.setPostalCode("94123");
		AdWhirlTargeting.setTestMode(true);

		adWhirlLayout = (PALayout)findViewById(R.id.adWhirl_layout); //if layout set in activity's layout
		//adWhirlLayout = new AdWhirlLayout(<Activity>, <Your AdWhirl SDK key>); //Alternate way to instantiate. Layout params need to be set and added to content.
		
		adWhirlLayout.setAdWhirlInterface(<class that implements AdWhirlInterface>);
		adWhirlLayout.setMaxWidth((int) (diWidth * density));
		adWhirlLayout.setMaxHeight((int) (diHeight * density));
				
4. Add the following code in the method to be implemented for AdWhirlInterface:
			
		public void adWhirlGeneric() {
			// your code here
		}

5. Set up Quattro ad settings to fit our case (Quattro is a dead ad integration which we can use for full integration of PlacePlayAds by very minor tweaking):

		Site ID: <YOUR PLACEPLAY APP ID HERE>
		Publisher ID: <Any acceptable string> // This value is ignored in the SDK

6. Under Backfill Priority, set Quattro to 1 so it's always first in line if location is available.

7. Under App Settings, set "Allow Location Access" to On.
		
## Sample App

The PlacePlay Ads SDK includes two sample projects at /Samples/

1. PlacePlayAdsSample/
	This is the solo PlacePlayAds implementation sample. It also includes multiple view controllers(Only active during Get Ad Solo button click) to demonstrate the singleton ad view technique. This maintains the
	ad view state as the user navigates between different screens, which generally results in higher click-through rates. Click "Next" to test this.

2. PlacePlayAdsAdwhirlSample/
	This is a sample for AdWhirl integration with PlacePlayAds (Using the Quattro Fix).
