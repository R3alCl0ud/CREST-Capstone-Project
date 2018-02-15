using System.Collections;
using System.Collections.Generic;
using UnityEngine;



namespace Platforms {
	
	public class Platform : MonoBehaviour {

		public GameObject spike_pref; // is about 0.88 units wide

		private List<GameObject> spikes;


		// public methods
		// Use this for initialization
		public void Start() {
			spikes = new List<GameObject>();
			//generateSpikes();
		}
	
		// Update is called once per frame
		public void Update() {

		}

		public void setLength(float length) {
			gameObject.transform.localScale = new Vector3(length, 0.5f, 1);
		}

		public void OnDestroy() {
			spikes.ForEach(spike => {
				GameObject.Destroy(spike);
			});
		}

		protected Vector3 getEndPoint(GameObject platform) {
			return platform.transform.position + new Vector3(platform.transform.localScale.x / 2, 0, 0);
		}

		public void generateSpikes(Vector2 gapsize) {


		}


	}
}