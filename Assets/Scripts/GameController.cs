using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameController : MonoBehaviour {

	// public member fields
	public GameObject platform_pref, spike_pref, player, GOText;


	// private member fields
	private List<GameObject> platforms;

	// protected member fields


	// public member methods
	public void Start() {
		platforms = new List<GameObject>();
		player = GameObject.FindGameObjectWithTag("Player");
		foreach (GameObject platform in GameObject.FindGameObjectsWithTag("Platform")) {
			platforms.Add(platform);
		}
	}

	public void Update() {
		generatePlatforms();
		for (int i = platforms.Count - 1; i >= 0; i--) {
			GameObject plat = platforms[i];
			if ((getEndPoint(plat) - player.transform.position).x <= -9) {
				platforms.Remove(plat);
				Destroy(plat);
			}
		}
	}

	public void GameOver() {
		// run game over code
		GOText.SetActive(true);
	}

	public void generatePlatforms() {
		// X: CurrentPos + 8.7 + (PlatformL / 2)
		GameObject platform = platforms[platforms.Count - 1];

		if ((((platform.transform.position.x) - player.transform.position.x) +
		    (platform.transform.localScale.x / 2)) < 9.5) {

			platforms.Add(Instantiate<GameObject>(platform_pref));
			GameObject platform_new = platforms[platforms.Count - 1];

			float gapW = Random.Range(2.0f, 3.1f);

			// Change to Vector2 magnitude (soon(tm)?)
			bool gap = gapW <= 2.5f ? false : true;
			float height = Random.Range(-1.5f, 1.51f);

			float p_height = platform.transform.position.y;
			height = height + p_height > -20.0f ? (gap && height > 1.25f ? 0:height): 0;
			platform_new.SendMessage("setLength", Random.Range(5.0f, 21.0f));

			platform_new.transform.SetPositionAndRotation(getEndPoint(platform) + new Vector3(getPlatLen(platform_new) + gapW, height, 0), Quaternion.identity);
			platform_new.SendMessage("generateSpikes", new Vector2(gapW, height));
		}
	}


	protected Vector3 getEndPoint(GameObject platform) {
		return platform.transform.position + new Vector3(platform.transform.localScale.x / 2, 0, 0);
	}

	protected float getPlatLen(GameObject plat) {
		return plat.transform.localScale.x / 2;
	}
}
