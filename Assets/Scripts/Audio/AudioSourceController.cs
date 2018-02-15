using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AudioSourceController : MonoBehaviour {

	private AudioSource theme;

	void Awake(){
		theme = GetComponent<AudioSource>();
		if (theme == null) {
			theme = gameObject.AddComponent<AudioSource>();
		}
		
	}

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
